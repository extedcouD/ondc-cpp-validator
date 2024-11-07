# C++ api validator

no [ if | else | when| then ] a **test** based approch

### what is a **TEST**

its a JSON object that can generate a c++ function which returns true or false

### test Object:

    {
        path: json.path. sperated.with.dot    {AUTO-CORRECT INPUT}
        type: EXISTANCE | REGEX | MATCH | ARRAY {DROPDOWN}
        params?: []  {COINDTIONALLY RENDEREND FIELD}
        value: any_string {normal input field or a conditional dorpdown}
    }

type: EXISTANCE >> value: EXISTS | NOT-EXISTS

type: REGEX >> value: "any regex" (enum validations will happen through regex)

type: MATCH >> value: dot.seperated.path or a constant value >> params: [lesser,equal,number,timestamp] // futher discussion

type: ARRAY >> // further discussion params can be [AnyOne,All,Any,]

## Two properties:

- conditions **tests**
- validation **test**

### validation Object:

    {
        conditions?: [TEST_OBJECTS] // optional object
        validation: TEST_OBJECT  // Still not sure wheter array or not
    }

#### simulation of AND

    {
        conditions: [test1,test2]
        validation: test
    }

#### simulation of OR

    {
        conditions: [test1]
        validation: test
    },
    {
        conditions: [test2]
        validation: test
    }

### FINALLY IN BUILD.YAML ADD A X-TESTS section with all the required validations objects which can be easily integrated with the dev-guide-editor

```
x-tests:
    search:
        - validation:
            path: message.intent.order_id
            type: EXISTANCE
            value: EXISTS
        - conditions: TEST_OBJECT2
          validation: ...
    on_search:
        - ...
```
