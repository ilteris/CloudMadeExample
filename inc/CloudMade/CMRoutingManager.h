//
//  CMRoutingManager.h
//  Routing
//
//  Created by Dmytro Golub on 12/7/09.
//  Copyright 2009 CloudMade. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>
#import "CMRouteDetails.h"

@class CMRoute;
@class CMRouteSammury;
@class RMMapView;
@class TokenManager;


/** \file CMRoutingManager.h 
 \brief A file with classes for routing  
 */

//! Enumeration which describes available vehicles for routing 
typedef enum _CMRoutingVehicle
{
	CMVehicleCar, /**< car route*/
	CMVehicleBike,/**< bicycle route*/
	CMVehicleWalking/**<  feet route*/
} CMRoutingVehicle;

//! Enumeration for start and end point of the route 
typedef enum _CMRoutePoint
{
	CMRouteStartPoint, /**< start point*/
	CMRouteFinishPoint,/**< end point*/
} CMRoutePoint;

//! Delegate for the CMRoutingManager \sa CMRoutingManager
@protocol CMRoutingManagerDelegate 
/**
 *  Called when route is found
 *  @param route built route \sa CMRoute
 *  @param routeSummary route summary \sa CMRouteSammury  
 */
-(void) routeDidFind:(CMRoute*) route summary:(CMRouteSammury*) routeSummary;  
@optional
/**
 *  Called when route is not found
 *  @param desc error description
 */
-(void) routeNotFound:(NSString*) desc;
/**
 *  Called when route is found
 *  @param details route details
 */
-(void) routeDidFind:(CMRouteDetails*) details;  
/**
 *  Called before route search starts
 */
-(void) routeSearchWillStarted;
@end

//! Class which builds route 
@interface CMRoutingManager : NSObject
{
	RMMapView* _mapView;
	id<CMRoutingManagerDelegate> delegate;
	CMRoute* _route;
	CMRouteSammury* _routeSammury;
	NSArray* _routeInstructions;
	CLLocationCoordinate2D _startRoutePoint;
	CLLocationCoordinate2D _endRoutePoint;	
	UIImage* _startRoutePointImage;
	UIImage* _endRoutePointImage;
	TokenManager* _tokenManager;
	BOOL _simplifyRoute;
	float _distance;
}
//! delegate \sa  CMRoutingManagerDelegate
@property (nonatomic,retain) id<CMRoutingManagerDelegate> delegate;

@property (readwrite) BOOL simplifyRoute;
@property (readwrite) float distance;


/**
 *  Initializes class
 *  @param mapView map where route will be drawn
 */
-(id) initWithMapView:(RMMapView*) mapView tokenManager:(TokenManager*) tokenManager;
/**
 *  searches for route 
 *  @param from start point of the route
 *  @param to end point of the route
 *  @param vehicle route type \sa CMRoutingVehicle
 */
-(void) findRouteFrom:(CLLocationCoordinate2D) from to:(CLLocationCoordinate2D) to onVehicle:(CMRoutingVehicle) vehicle; 
/**
 *  searches for route 
 *  @param vehicle rebuild build for the given vehicle \sa CMRoutingVehicle
 */
-(void) reloadRouteWithVehicle:(CMRoutingVehicle) vehicle;
/**
 *  remove route from the map 
 */
-(void) removeRouteFromMap;
/**
 *  returns route summary \sa  CMRouteSammury
 */
-(CMRouteSammury*) routeSummary;
/**
 *  returns route instructions \sa  RouteInstruction
 */
-(NSArray*) routeInstructions;
/**
 * Sets image for route points
 * @param image point image
 * @param point point specification \sa CMRoutePoint
 */ 
-(void) image:(UIImage*) image forPoint:(CMRoutePoint) point;  
@end
