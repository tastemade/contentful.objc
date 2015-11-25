//
//  CDAArray+Private.h
//  ContentfulSDK
//
//  Created by Boris Bügling on 04/03/14.
//
//

#import <ContentfulDeliveryAPI/CDAArray.h>
#import <ContentfulDeliveryAPI/CDAGenericsStubs.h>

@interface CDA_GENERICS(CDAArray, __covariant ObjectType) ()

@property (nonatomic, readonly) NSURL* nextPageUrl;
@property (nonatomic, readonly) NSURL* nextSyncUrl;
@property (nonatomic) NSDictionary* query;

-(id)initWithItems:(CDA_GENERICS(NSArray, ObjectType)*)items client:(CDAClient*)client;

@end
