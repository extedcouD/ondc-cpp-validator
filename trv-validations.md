## MOBILITY TRV11 2.0.1

### search

1. payload is not empty isObjectEmpty();
2. if statement for missing fields [data.message,data.context,data.message.intent, and if they are empty]
3. SchemaValidation : THROUGH JSON SCHEMA : additonalProperites,required schema item,required schema enums, type[uuid,number]

4. context validations (if statments for existance) :

   1. context.location.city.code
   2. context.location.country.code
   3. save message_id and transaction_id

5. message validations

   1. stops = data.message.intent?.fullfiment?.stops

      1. check length or array > 0
      2. check existance
      3. valid stop type: [START , END]
      4. existance for both types START AND END
      5. existance of gps and CheckGpsPrecision(6 digit precision)

   _note: missing array have multiple starts and end , vechile.categor should be METRO_

   2. payments:

      1. payaments.collected_by existance and enum
      2. SETING VALUE OF COLLECTED BY FOR FUTURE REFERENCE

   3. tags validation:

      1. SEPRATE OBJECT RULES FOR DIFFERENT TAG-GROUPS
         1. tag.descriptor.code enum ['BUYER_FINDER_FEES','SETTLEMENT_TERMS']
         2. based on above enum different checks on object
         3. if BUYER_FINDER_FEES -> BUYER_FINDER_FEES_PERCENTAGE,BUYER_FINDER_FEES_TYPE and there value type (integer,or a url in SETTLEMENT_TERMS)

### on-search

0. schema

1. context

   1. check context with saved values
   2. then mandatory and enums

2. message:

   1. catalog existance

      1. catalog.descriptor.name should be present
      2. existance of provider 0. iterate through provider

         1. unique PROVIDER_ID,ITEM_IDS,STOREDLOCATIONS ETC in the array
         2. existance fullilments in provider
            1. iterate through fullilments unique ids
               1. fullfilment.type should be enum
               2. fullfilment.vechicle.catergory should be enum
               3. fullfilment.stop must be uniqe name
         3. provider.category.descriptor.code : ENUM
         4. provider.time.range.start if present then correnct format
         5. items
         6. iterrate through
         7. item.id exists and unitque
         8. price object check
         9. **all the fullfillment_ids in the items should be valid with exsiting fulliment.id**
         10. payments existance
         11. payment.collected_by enum
         12. tags validation

      3. save providerIDs,providerLocastionsID,itemIds,storedLocations,storeFullfilments

   _note: missing start and end stops in search and on_search should be same_

### select

1. message.order.items.id must be a valid one from on_search
2. provider id must be valid
3. quantity must be number

### on_select

1. provider id must be same as previous if it exists
2. same validations of fulfillments
