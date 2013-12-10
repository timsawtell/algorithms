//
//  AppDelegate.m
//  algorithms
//
//  Created by Tim Sawtell on 10/12/2013.
//  Copyright (c) 2013 . All rights reserved.
//

#define NSLog(fmt...) NSShutUp(__PRETTY_FUNCTION__,fmt)
#define UTF8FMT(fmt,argL) \
[NSString.alloc initWithFormat:fmt arguments:argL].UTF8String

void NSShutUp(const char*func, id fmt, ...) {
    if (![fmt isKindOfClass:NSString.class]) {
        // it's not a string (aka. the formatter), so print it)
        fprintf (stderr, "%s\n", [[NSString stringWithFormat:@"%@",fmt,nil] UTF8String]);
    } else {
        va_list argList;
        va_start (argList, fmt);
            fprintf (stderr, "%s\n", UTF8FMT(fmt, argList));
        va_end  (argList);
    }
}

#import "AppDelegate.h"
#import "constants.h"
#import "headers.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    // Override point for customization after application launch.
    self.window.backgroundColor = [UIColor whiteColor];
    [self.window makeKeyAndVisible];
    
    NSLog(@"\nint randomArray[SIZE_OF_ARRAY] = {13, 46, 24, 23, 48, 44, 21, 50, 29, 12, 26, 1, 27, 40, 17, 3, 9, 25, 4, 38, 32, 43, 18, 45, 8, 2, 14, 11, 20, 39, 10, 15, 35, 6, 34, 41, 5, 47, 49, 37, 30, 22, 33, 16, 36, 7, 28, 31, 19, 42};\n");
    [self bubbleSort];
    [self selectionSort];
    [self insertionSort];
    [self mergeSort];
    [self quickSort];
    return YES;
}

- (void)bubbleSort
{
    NSLog(@"Start Bubble Sort");
    int *result = sort_bubble();
    [self printResults:result];
}

- (void)selectionSort
{
    NSLog(@"Start Selection Sort");
    int *result = sort_selection();
    [self printResults:result];
}

- (void)insertionSort
{
    NSLog(@"Start Insertion Sort");
    int *result = sort_insertion();
    [self printResults:result];
}

- (void)mergeSort
{
    NSLog(@"Start Merge Sort");
    int *result = sort_merge();
    [self printResults:result];
}

- (void)quickSort
{
    NSLog(@"Start Quick Sort");
    int *result = sort_quick();
    [self printResults:result];
}

- (void)printResults:(int*)result
{
    NSMutableString *string= [NSMutableString new];
    for (int i = 0; i < SIZE_OF_ARRAY; i++) {
       // NSLog(@"%d", result[i]);
        NSString *sep = @",";
        if (i == SIZE_OF_ARRAY - 1) sep = @"";
        [string appendFormat:@"%d%@", result[i], sep];
    }
    NSLog(@"%@", string);
    NSLog(@"Number of iterations: %d", numberOfIterations);
    NSLog(@"Number of inner iterations (total): %d\n", numberOfInnerIterations);
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
