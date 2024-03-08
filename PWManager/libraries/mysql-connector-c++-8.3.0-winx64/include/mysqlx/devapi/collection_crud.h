/*
 * Copyright (c) 2015, 2023, Oracle and/or its affiliates.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2.0, as
 * published by the Free Software Foundation.
 *
 * This program is also distributed with certain software (including
 * but not limited to OpenSSL) that is licensed under separate terms,
 * as designated in a particular file or component or in included license
 * documentation.  The authors of MySQL hereby grant you an
 * additional permission to link the program and your derivative works
 * with the separately licensed software that they have included with
 * MySQL.
 *
 * Without limiting anything contained in the foregoing, this file,
 * which is part of MySQL Connector/C++, is also subject to the
 * Universal FOSS Exception, version 1.0, a copy of which can be found at
 * http://oss.oracle.com/licenses/universal-foss-exception.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License, version 2.0, for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA
 */

#ifndef MYSQLX_COLLECTION_CRUD_H
#define MYSQLX_COLLECTION_CRUD_H

/**
  @file
  Declarations for CRUD operations on document collections.

  Classes declared here represent CRUD operations on a document
  collection. An Object of a class such as CollectionAdd represents
  a "yet-to-be-executed" operation and stores all the parameters of the
  operation. The operation is sent to server for execution only when
  `execute()` method is called.

  The following classes for collection CRUD operations are defined:
  - CollectionAdd
  - CollectionRemove
  - CollectionFind
  - CollectionModify

  CRUD operation objects can be created directly, or assigned from
  result of DevAPI methods that create such operations:
  ~~~~~~
     CollectionAdd  add_op(coll);
     CollectionFind find_op = coll.find(...).sort(...);
  ~~~~~~

  CRUD operation objects have methods which can modify the operation
  before it gets executed. For example `CollectionAdd::add()`
  appends a document to the list of documents that should be added
  by the given CollectionAdd operation. These methods can be chained
  as allowed by the fluent API grammar.

  @internal

  The order of fluent API calls is expressed by base classes, such as
  Collection_find_base, which are composed from CRUD templates defined
  in crud.h. The order of templates determines the allowed order of fluent
  API calls.
*/


#include "common.h"
#include "result.h"
#include "executable.h"
#include "crud.h"


namespace mysqlx {
MYSQLX_ABI_BEGIN(2,0)

class Session;
class Collection;
class Table;

template<>
PUBLIC_API common::Value Value::get<common::Value>() const;

// ----------------------------------------------------------------------

/*
  Adding documents to a collection
  ================================
*/

class CollectionAdd;

namespace internal {

/*
  Note: using empty class instead of alias/typedef to help Doxygen correctly
  expand templates.
*/

struct Collection_add_base
  : public Executable<Result, CollectionAdd>
{};

}


/**
  An operation which adds documents to a collection.

  Documents to be added by this operation are specified with various variants
  of `add()` method.

  Each document must have a unique identifier which is stored in `_id`
  field of the document. Document identifiers are character strings no longer
  than 32 characters. If added document does not have `_id` field, a unique
  identifier is generated for it. Document identifier generated by a given
  collection add operation can be examined using `Result::getDocumentIds()`
  method. Generated document identifiers are strings of 32 hexadecimal digits,
  like this one `0512020981044082E6119DFA0E4C0584`.

  @note Generated document identifiers are based on UUIDs but they are not
  valid UUIDs (fields are reversed).

  @ingroup devapi_op

  @internal
  The various `add()` methods are implemented in terms of `do_add()` method
  defined by Collection_add_detail class. This method passes documents to
  the internal implementation object.
*/

class CollectionAdd
  : public internal::Collection_add_base
  , internal::Collection_add_detail
{
public:

  /**
    Create an empty add operation for the given collection.
  */

  CollectionAdd(Collection &coll)
  {
    try {
      reset(internal::Crud_factory::mk_add(coll));
    }
    CATCH_AND_WRAP
  }

  CollectionAdd(const internal::Collection_add_base &other)
  {
    internal::Collection_add_base::operator=(other);
  }

  CollectionAdd(internal::Collection_add_base &&other)
  {
    internal::Collection_add_base::operator=(std::move(other));
  }

  using internal::Collection_add_base::operator=;


  /**
    Add all documents from a range defined by two iterators.
  */

  template <typename It>
  CollectionAdd& add(const It &begin, const It &end)
  {
    try {
      do_add(get_impl(), begin, end);
      return *this;
    }
    CATCH_AND_WRAP
  }

  /**
    Add all documents within given container.

    Any container type for which `std::begin()`/`std::end()` are defined
    should work.
  */

  template <class Container>
  CollectionAdd& add(const Container &c)
  {
    try {
      do_add(get_impl(), c);
      return *this;
    }
    CATCH_AND_WRAP
  }

  /**
    Add document(s) to a collection.

    Documents can be described by JSON strings or DbDoc objects.
  */

  template <typename... Types>
  CollectionAdd& add(const Types&... docs)
  {
    try {
      do_add(get_impl(), docs...);
      return *this;
    }
    CATCH_AND_WRAP
  }

protected:

  using Impl = common::Collection_add_if;

  Impl* get_impl()
  {
    return static_cast<Impl*>(internal::Collection_add_base::get_impl());
  }

};


// ----------------------------------------------------------------------


/*
  Removing documents from a collection
  ====================================
*/

class CollectionRemove;

namespace internal {

struct Collection_remove_cmd
  : public Executable<Result, CollectionRemove>
{};

struct Collection_remove_base
  : public Sort< Limit< Bind_parameters< Collection_remove_cmd > > >
{};

}  // internal namespace


/**
  An operation which removes documents from a collection.

  @ingroup devapi_op

  @internal
  Note: All methods that modify remove operation are defined by the base
  class.
*/

class CollectionRemove
  : public internal::Collection_remove_base
{

public:

  /**
    Create an operation which removes selected documnets from the given
    collection.

    Documents to be removed are specified by the given Boolean expression.
  */

  CollectionRemove(Collection &coll, const string &expr)
  {
    try {
      reset(internal::Crud_factory::mk_remove(coll, expr));
    }
    CATCH_AND_WRAP
  }


  CollectionRemove(const internal::Collection_remove_cmd &other)
  {
    internal::Collection_remove_cmd::operator=(other);
  }

  CollectionRemove(internal::Collection_remove_cmd &&other)
  {
    internal::Collection_remove_cmd::operator=(std::move(other));
  }

  using internal::Collection_remove_cmd::operator=;

};


// ----------------------------------------------------------------------

/*
  Searching for documents in a collection
  =======================================
*/

class CollectionFind;

namespace internal {

struct Collection_find_cmd
  : public Executable<DocResult, CollectionFind>
{};

struct Collection_find_base
  : public Group_by< Having< Sort< Limit< Offset< Bind_parameters<
      Set_lock< Collection_find_cmd, common::Collection_find_if >
    > > > > > >
{};

}  // internal namespace


/**
  An operation which returns all or selected documents from a collection.

  @ingroup devapi_op
*/

class CollectionFind
  : public internal::Collection_find_base
  , internal::Collection_find_detail
{

  using Operation = internal::Collection_find_base;

public:

  /**
    Create an operation which returns all documents from the given collection.
  */

  CollectionFind(Collection &coll)
  {
    try {
      reset(internal::Crud_factory::mk_find(coll));
    }
    CATCH_AND_WRAP
  }

  /**
    Create an operation which returns selected documents from the given
    collection.

    Documents to be returned are specified by the given Boolean expression.
  */

  CollectionFind(Collection &coll, const string &expr)
  {
    try {
      reset(internal::Crud_factory::mk_find(coll, expr));
    }
    CATCH_AND_WRAP
  }


  CollectionFind(const internal::Collection_find_cmd &other)
  {
    internal::Collection_find_cmd::operator=(other);
  }

  CollectionFind(internal::Collection_find_cmd &&other)
  {
    internal::Collection_find_cmd::operator=(std::move(other));
  }

  using internal::Collection_find_cmd::operator=;


public:

  /**
    Specify a projection for the documents returned by this operation.

    Projection is either a single document expression given by `expr(<string>)`
    or a list (or collection) of strings of the form
    `"<expression> AS <path>"`. In the latter case each `<expression>`
    is evaluated and `<path>` specifies where to put the value of
    the expression in the resulting document (see `CollectionModify` for more
    information about document paths).
  */

  template <typename... Expr>
  Operation& fields(Expr... proj)
  {
    try {
      get_impl()->clear_proj();
      do_fields(get_impl(), proj...);
      return *this;
    }
    CATCH_AND_WRAP
  }

protected:

  using Impl = common::Collection_find_if;

  Impl* get_impl()
  {
    return static_cast<Impl*>(internal::Collection_find_base::get_impl());
  }

};


// ----------------------------------------------------------------------

/*
  Modifying documents in a collection
  ===================================
*/

class CollectionModify;


namespace internal {

class CollectionReplace;

struct Collection_modify_cmd
  : public Executable<Result, CollectionModify>
{};

struct Collection_modify_base
  : public Sort< Limit< Bind_parameters< Collection_modify_cmd > > >
{};

}  // internal namespace


/**
  An operation which modifies all or selected documents in a collection.

  Note that in operations such as `set()`, `unset()`, `arrayInsert()` and
  `arrayAppend()` the field argument is specified as a document path. It can be
  a simple field name, but it can be a more complex expression like
  `$.foo.bar[3]`. One consequence of this is that document field names that
  contain spaces or other special characters need to be quoted, for example one
  needs to use this form
  ```
    .unset("\"field name with spaces\"")
  ```
  as `.unset("field name with spaces")` would be an invalid document path
  expression.

  Note also that wildcard paths that use `*` or `**` are not valid for these
  operations that modify documents.

  See [MySQL Reference Manual](https://dev.mysql.com/doc/refman/en/json.html#json-path-syntax)
  for more information on document path syntax supported by MySQL server.

  @ingroup devapi_op
*/

class CollectionModify
  : public internal::Collection_modify_base
{

public:

  /**
    Create an operation which modifies selected documents in the given
    collection.

    Documents to be modified are specified by the given Boolean expression.
  */

  CollectionModify(Collection &coll, const string &expr)
  {
    try {
      reset(internal::Crud_factory::mk_modify(coll, expr));
    }
    CATCH_AND_WRAP
  }


  CollectionModify(const internal::Collection_modify_cmd &other)
  {
    internal::Collection_modify_cmd::operator=(other);
  }

  CollectionModify(internal::Collection_modify_cmd &&other)
  {
    internal::Collection_modify_cmd::operator=(std::move(other));
  }

  using internal::Collection_modify_cmd::operator=;

  /**
    Set the given field in a document to the given value.

    The field is given by a document path. The value can be either a direct
    literal, `DbDoc` instance or an expression given as `expr(<string>)`, to be
    evaluated on the server.
  */

  CollectionModify& set(const Field &field, const Value &val)
  {
    try {
      get_impl()->add_operation(Impl::SET, field,
                                val.get<common::Value>());
      return *this;
    }
    CATCH_AND_WRAP
  }

  /**
    Remove the given field from a document.

    The field is given by a document path.
  */

  CollectionModify& unset(const Field &field)
  {
    try {
      get_impl()->add_operation(Impl::UNSET, field);
      return *this;
    }
    CATCH_AND_WRAP
  }

  /**
    Insert a value into an array field of a document.

    The `field` parameter should be a document path pointing at a location
    inside an array field. The given value is inserted at this position.
  */

  CollectionModify& arrayInsert(const Field &field, const Value &val)
  {
    try {
      get_impl()->add_operation(Impl::ARRAY_INSERT, field,
                                val.get<common::Value>());
      return *this;
    }
    CATCH_AND_WRAP
  }

  /**
    Append a value to an array field of a document.

    The `field` parameter should be a document path pointing at an array
    field inside the document. The given value is appended at the end of the
    array.
  */

  CollectionModify& arrayAppend(const Field &field, const Value &val)
  {
    try {
      get_impl()->add_operation(Impl::ARRAY_APPEND, field,
                                val.get<common::Value>());
      return *this;
    }
    CATCH_AND_WRAP
  }

  /**
    Apply JSON Patch to a target JSON document.

    The JSON Patch format is defined by
    <a href=https://tools.ietf.org/html/rfc7386>RFC7386</a>.

    A document patch is similar to a JSON object, with the key difference that
    document field values can be nested expressions in addition to literal
    values.

    The patch contains instructions of how the source document is to be modified
    producing a derived document. By default, all fields from the source
    document are copied to the resulting document. If patch sets a field to NULL,
    the field of that name in the source is skipped from the result, identifiers
    and function calls are evaluated against the original source document.

  */

  CollectionModify& patch(const string &val)
  {
    try {
      get_impl()->add_operation(
        Impl::MERGE_PATCH, "$", (const common::Value&)expr(val)
      );
      return *this;
    }
    CATCH_AND_WRAP
  }

protected:

  using Impl = common::Collection_modify_if;

  Impl* get_impl()
  {
    return static_cast<Impl*>(internal::Collection_modify_base::get_impl());
  }

};

MYSQLX_ABI_END(2,0)
}  // mysqlx namespace

#endif
