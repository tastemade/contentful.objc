//
//  CDAEntry+Private.h
//  ContentfulSDK
//
//  Created by Boris Bügling on 04/03/14.
//
//

#import "CDAEntry.h"

@interface CDAEntry ()

-(CDA_GENERICS(NSArray, CDAAsset*)*)findUnresolvedAssets;
-(CDA_GENERICS(NSArray, CDAEntry*)*)findUnresolvedEntries;
-(NSDictionary*)localizedFields;
-(void)resolveLinksWithIncludedAssets:(NSDictionary*)assets
                              entries:(NSDictionary*)entries
                           usingBlock:(CDAResource* (^)(CDAResource* resource, NSDictionary* assets,
                                                        NSDictionary* entries))resolver;
-(void)setValue:(id)value forFieldWithName:(NSString *)key;

@end
