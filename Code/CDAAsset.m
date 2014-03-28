//
//  CDAAsset.m
//  ContentfulSDK
//
//  Created by Boris Bügling on 05/03/14.
//
//

#import "CDAAsset.h"
#import "CDAClient+Private.h"
#import "CDAResource+Private.h"
#import "CDASpace+Private.h"

const CGFloat CDAImageQualityOriginal = 0.0;

@interface CDAAsset ()

@property (nonatomic) NSMutableDictionary* localizedFields;

@end

#pragma mark -

@implementation CDAAsset

+(NSString *)CDAType {
    return @"Asset";
}

#pragma mark -

-(NSString *)description {
    return [NSString stringWithFormat:@"CDAAsset of type %@ at URL %@", self.MIMEType, self.URL];
}

-(NSDictionary *)fields {
    return self.localizedFields[self.client.space.defaultLocale];
}

-(NSURL *)imageURLWithSize:(CGSize)size {
    return [self imageURLWithSize:size quality:CDAImageQualityOriginal format:CDAImageFormatOriginal];
}

-(NSURL *)imageURLWithSize:(CGSize)size quality:(CGFloat)quality format:(CDAImageFormat)format {
    if (!self.isImage) {
        return self.URL;
    }
    
    NSMutableDictionary* parameters = [@{} mutableCopy];
    
    if (!CGSizeEqualToSize(size, CGSizeZero)) {
        parameters[@"w"] = @(size.width);
        parameters[@"h"] = @(size.height);
    }
    
    if (quality != CDAImageQualityOriginal) {
        parameters[@"q"] = @(quality * 100);
    }
    
    switch (format) {
        case CDAImageFormatJPEG:
            parameters[@"fm"] = @"jpg";
            break;
        case CDAImageFormatPNG:
            parameters[@"fm"] = @"png";
            break;
        default:
            break;
    }
    
    if (parameters.count == 0) {
        return self.URL;
    }
    
    NSMutableString* imageUrlString = [self.URL.absoluteString mutableCopy];
    
    [imageUrlString appendString:@"?"];
    
    NSMutableArray* queryParameters = [@[] mutableCopy];
    [parameters enumerateKeysAndObjectsUsingBlock:^(NSString* key, NSString* value, BOOL *stop) {
        [queryParameters addObject:[NSString stringWithFormat:@"%@=%@", key, value]];
    }];
    
    [imageUrlString appendString:[queryParameters componentsJoinedByString:@"&"]];
    
    return [NSURL URLWithString:imageUrlString];
}

-(id)initWithDictionary:(NSDictionary *)dictionary client:(CDAClient*)client {
    self = [super initWithDictionary:dictionary client:client];
    if (self) {
        self.localizedFields = [@{} mutableCopy];
        
        if (dictionary[@"fields"]) {
            if (self.localizationAvailable) {
                for (NSString* locale in self.client.space.localeCodes) {
                    self.localizedFields[locale] = [self localizedDictionaryFromDictionary:dictionary[@"fields"] forLocale:locale];
                }
            } else {
                self.localizedFields[self.client.space.defaultLocale] = dictionary[@"fields"];
            }
        }
    }
    return self;
}

-(BOOL)isImage {
    return [self.MIMEType hasPrefix:@"image/"];
}

-(NSDictionary*)localizedDictionaryFromDictionary:(NSDictionary*)dictionary forLocale:(NSString*)locale {
    NSMutableDictionary* result = [@{} mutableCopy];
    
    [dictionary enumerateKeysAndObjectsUsingBlock:^(NSString* key, NSDictionary* value, BOOL *stop) {
        id localizedValue = value[locale];
        
        if (!localizedValue) {
            return;
        }
        
        result[key] = localizedValue;
    }];
    
    return [result copy];
}

-(NSString *)MIMEType {
    return self.fields[@"file"][@"contentType"];
}

-(void)resolveWithSuccess:(void (^)(CDAResponse *, CDAResource *))success
                  failure:(void (^)(CDAResponse *, NSError *))failure {
    if (self.fetched) {
        [super resolveWithSuccess:success failure:failure];
        return;
    }
    
    [self.client fetchAssetWithIdentifier:self.identifier
                                  success:^(CDAResponse *response, CDAAsset *asset) {
                                      if (success) {
                                          success(response, asset);
                                      }
                                  } failure:failure];
}

-(CGSize)size {
    NSDictionary* size = self.fields[@"file"][@"details"][@"image"];
    return size ? CGSizeMake([size[@"width"] floatValue], [size[@"height"] floatValue]) : CGSizeZero;
}

-(NSURL *)URL {
    NSString* url = self.fields[@"file"][@"url"];
    if (!url) {
        return nil;
    }
    return [NSURL URLWithString:[NSString stringWithFormat:@"%@:%@", self.client.protocol, url]];
}

@end
