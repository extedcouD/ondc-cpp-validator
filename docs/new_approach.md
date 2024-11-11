## NEW JSON-CODE-GENERATION

test object: a JSON which can be converted into a function which returns either True or False

defination:

```
{
    _NAME_: "name of the validation"
    _CONTEXT_: "dot.seprated.object which determines the scope of test"
    any-variable-name: "path.to.property OR fixed array OR boolean Map"
    _RETURN_: "a boolean operation which can use difined variable names and its properties"
    _CONTINUE_ : similar to return but skip test if true
}

```

### Examples of variable names:

```
1. "A" : context.trasactionID >> output: ["abscerfdd"] or ["NULL"]
2. "B" : ["PAID","NOT_PAID"] >> output: ["PAID,"NOT_PAID"]
3. "C" : context.domain == "RET:10" >> output : [TRUE] or ["FALSE"]
```

_note: a variable is basically a get function which returns NULL if get function fails
and it always returns a one-dimension array_

**VARIABLE ARE NOT JUST AN ARRAY BUT A OBJECT OF PREDIFINED CLASS WITH PROPERTIES LIKE VAR.ALL, VAR.ANY, VAR[0], VAR.ARE_UNIQUE**

### Example of _RETURN_:

```
1. "_RETURN_" : A.ALL IN B
2. "_RETURN_" : B.ANY FOLLOW re(`regex`)
3. "_RETURN_" : A IS B && B.ALL in C
5. "_RETURN_" : D.ARE_UNIQUE
```

### Complete examples

```
const checks = {
  on_search: [
    {
      _NAME_: "requiredContext",
      domain: "context.domain",
      enum: ["ONDC:RET11"],
      _RETURN_: "domain.ALL IN enum",
    },
    {
      _NAME_: "requiredTransactionID",
      domain: "context.transactionID",
      _RETURN_: "domain.ALL FOLLOW re('uuid ka regex')",
    },
    {
      _NAME_: "checkBppName",
      targetName: "message.catalog[`bpp/descriptor`].name",
      nulls: ["NULL"],
      _RETURN_: "targetName.ALL NOT IN nulls",
    },
    {
      _NAME_: "checkAllProvidersHaveUniqueID",
      ids: "message.catalog[`bpp/provider`].id",
      null: ["NULL"],
      _RETURN_: "ids.ALL NOT IN null && ids.ARE_UNIQUE",
    },
    {
      _NAME_: "check_all_items_have_valid_fullfillment_id",
      _CONTEXT_: "message.catalog[`bpp/providers`]",
      items_ids: "message.catalog[`bpp/providers`].items.fulfillment_id",
      full_ids: "message.catalog[`bpp/providers`].fulfillments.id",
      _RETURN_: "items_ids.ALL IN full_ids",
    },
    {
      _NAME_: "check_payment_trascation_id",
      status: "message.payments.status == [`PAID`]", // [PAID,NOT_PAID,PAID] => [TRUE,FALSE,TRUE]
      transaction_id: "message.payments.transaction_id != [NULL]", // [abc,NULL,NULL] => [TRUE,FALSE,FALSE]
      _RETURN_: "status IS transaction_id",
    },
    {
        _NAME_: "check_STOP_END"
        types: "message.intent.stops.type"
        allowed: ["START","END"]
        _RETURN_: allowed.ALL in types
    }
  ],
};
```
