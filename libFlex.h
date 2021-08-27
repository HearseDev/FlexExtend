@import Foundation;
@import UIKit;


@interface FLEXProperty : NSObject
@property (nonatomic, readonly) NSString *fullDescription;
@end
@interface FLEXIvar : NSObject
@end
@interface FLEXMethod : NSObject
@property (nonatomic,strong) NSMutableString *listOfArgs;
@property (nonatomic, readonly) NSMethodSignature *signature;
@property (nonatomic, readonly) NSUInteger        numberOfArguments;
@property (nonatomic, readonly) NSString *selectorString;
@property (nonatomic, readonly) BOOL              isInstanceMethod;
-(NSString *)returnOrigSpecifierName:(NSString *)argType;
-(NSString *)returnArgName:(NSString *)argType forIndex:(int)index;

- (NSArray *)prettyArgumentComponents;
-(NSString *)prettyName;
- (NSString *)prettyNameForLogging;
- (NSArray *)prettyArgumentComponentsForLogging;
-(NSString *)returnTypeSpecifier:(NSString *)type;
@end

@interface FLEXObjectExplorer : NSObject
@property (nonatomic, readonly) id object;
@property (nonatomic, readonly) NSArray<FLEXProperty *> *properties;
@property (nonatomic, readonly) NSArray<FLEXIvar *> *ivars;
@property (nonatomic, readonly) NSArray<FLEXMethod *> *methods;
@property (nonatomic, readonly) NSArray<FLEXMethod *> *classMethods;
-(void)convertMethodsToText;
-(NSString *)getClassHeirarchy;
-(NSString *)getProperties;
-(NSString *)getIvars;
-(NSString *)getInstanceMethods;
-(NSString *)getClassMethods;
-(NSString *)logInstanceMethods;
-(NSString *)logClassMethods;
-(NSString *)joinAndGenerateHeader;
@end
@interface FLEXObjectExplorerViewController : UIViewController
@property (nonatomic, readonly) FLEXObjectExplorer *explorer;
- (void)loggingButtonPressed:(UIBarButtonItem *)sender;
- (void)addToolbarItems:(NSArray<UIBarButtonItem *> *)items;
@end

@interface FLEXRuntimeUtility : NSObject
+ (NSArray<Class> *)classHierarchyOfObject:(id)objectOrClass;
+ (NSString *)safeClassNameForObject:(id)object;
+ (NSString *)readableTypeForEncoding:(NSString *)encodingString;
@end
