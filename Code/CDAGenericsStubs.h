//
//  CDAGenericsStubs.h
//  ContentfulSDK
//
//  Created by Boris Bügling on 25/11/15.
//
//

// Thanks to https://gist.github.com/smileyborg/d513754bc1cf41678054

#if __has_feature(objc_generics)
#   define CDA_GENERICS(class, ...)      class<__VA_ARGS__>
#   define CDA_GENERICS_TYPE(type)       type
#else
#   define CDA_GENERICS(class, ...)      class
#   define CDA_GENERICS_TYPE(type)       id
#endif
