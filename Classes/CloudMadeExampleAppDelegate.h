//
//  CloudMadeExampleAppDelegate.h
//  CloudMadeExample
//
//  Created by freelancer on 6/30/10.
//  Copyright __MyCompanyName__ 2010. All rights reserved.
//

#import <UIKit/UIKit.h>

@class CloudMadeExampleViewController;

@interface CloudMadeExampleAppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
    CloudMadeExampleViewController *viewController;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet CloudMadeExampleViewController *viewController;

@end

