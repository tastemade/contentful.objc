//
//  CDAMapViewController.h
//  ContentfulSDK
//
//  Created by Boris Bügling on 02/04/14.
//
//

#import <ContentfulDeliveryAPI/CDAClient.h>
#import <UIKit/UIKit.h>

/**
 *  `CDAMapViewController` fetches Entries and displays them on a `MKMapView`.
 *
 *  You have to configure which Fields will be used to fill the `MKAnnotation` properties.
 */
@interface CDAMapViewController : UIViewController

/** @name Configure Data to Display */

/** Identifier for the Field which contains the coordinate for each `MKAnnotation`. */
@property (nonatomic, copy) NSString* coordinateFieldIdentifier;

/** Identifier for the Field which contains the subtitle for each `MKAnnotation`. */
@property (nonatomic, copy) NSString* subtitleFieldIdentifier;

/** Identifier for the Field which contains the title for each `MKAnnotation`. */
@property (nonatomic, copy) NSString* titleFieldIdentifier;

/** @name Configure Data to Fetch */

/**
 The client which is used to fetch Entries. Make sure to set it before displaying the view
 controller's view or an exception will be thrown unless `initWithCellMapping:items:` was used to
 initialize this view controller.
 
 The client is not retained.
 */
@property (nonatomic, weak) CDAClient* client;

/** The items which are currently displayed in this view controller's table view. */
@property (nonatomic, readonly) NSArray* items;

/**
 The query parameters used for fetching Entries. By default, all Entries from the Space associated
 with the client will be fetched.
 */
@property (nonatomic) NSDictionary* query;

@end
