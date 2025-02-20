//
// Copyright 2010-2023 Amazon.com, Inc. or its affiliates. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License").
// You may not use this file except in compliance with the License.
// A copy of the License is located at
//
// http://aws.amazon.com/apache2.0
//
// or in the "license" file accompanying this file. This file is distributed
// on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
// express or implied. See the License for the specific language governing
// permissions and limitations under the License.
//

#import <Foundation/Foundation.h>
#import <AWSCore/AWSCore.h>
#import "AWSIoTModel.h"
#import "AWSIoTResources.h"

NS_ASSUME_NONNULL_BEGIN

//! SDK version for AWSIoT
FOUNDATION_EXPORT NSString *const AWSIoTSDKVersion;

/**
 <fullname>IoT</fullname><p>IoT provides secure, bi-directional communication between Internet-connected devices (such as sensors, actuators, embedded devices, or smart appliances) and the Amazon Web Services cloud. You can discover your custom IoT-Data endpoint to communicate with, configure rules for data processing and integration with other services, organize resources associated with each device (Registry), configure logging, and create and manage policies and credentials to authenticate devices.</p><p>The service endpoints that expose this API are listed in <a href="https://docs.aws.amazon.com/general/latest/gr/iot-core.html">Amazon Web Services IoT Core Endpoints and Quotas</a>. You must use the endpoint for the region that has the resources you want to access.</p><p>The service name used by <a href="https://docs.aws.amazon.com/general/latest/gr/signature-version-4.html">Amazon Web Services Signature Version 4</a> to sign the request is: <i>execute-api</i>.</p><p>For more information about how IoT works, see the <a href="https://docs.aws.amazon.com/iot/latest/developerguide/aws-iot-how-it-works.html">Developer Guide</a>.</p><p>For information about how to use the credentials provider for IoT, see <a href="https://docs.aws.amazon.com/iot/latest/developerguide/authorizing-direct-aws.html">Authorizing Direct Calls to Amazon Web Services Services</a>.</p>
 */
@interface AWSIoT : AWSService

/**
 The service configuration used to instantiate this service client.
 
 @warning Once the client is instantiated, do not modify the configuration object. It may cause unspecified behaviors.
 */
@property (nonatomic, strong, readonly) AWSServiceConfiguration *configuration;

/**
 Returns the singleton service client. If the singleton object does not exist, the SDK instantiates the default service client with `defaultServiceConfiguration` from `[AWSServiceManager defaultServiceManager]`. The reference to this object is maintained by the SDK, and you do not need to retain it manually.

 For example, set the default service configuration in `- application:didFinishLaunchingWithOptions:`
 
 *Swift*

     func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        let credentialProvider = AWSCognitoCredentialsProvider(regionType: .USEast1, identityPoolId: "YourIdentityPoolId")
        let configuration = AWSServiceConfiguration(region: .USEast1, credentialsProvider: credentialProvider)
        AWSServiceManager.default().defaultServiceConfiguration = configuration
 
        return true
    }

 *Objective-C*

     - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
          AWSCognitoCredentialsProvider *credentialsProvider = [[AWSCognitoCredentialsProvider alloc] initWithRegionType:AWSRegionUSEast1
                                                                                                          identityPoolId:@"YourIdentityPoolId"];
          AWSServiceConfiguration *configuration = [[AWSServiceConfiguration alloc] initWithRegion:AWSRegionUSEast1
                                                                               credentialsProvider:credentialsProvider];
          [AWSServiceManager defaultServiceManager].defaultServiceConfiguration = configuration;

          return YES;
      }

 Then call the following to get the default service client:

 *Swift*

     let IoT = AWSIoT.default()

 *Objective-C*

     AWSIoT *IoT = [AWSIoT defaultIoT];

 @return The default service client.
 */
+ (instancetype)defaultIoT;

/**
 Creates a service client with the given service configuration and registers it for the key.

 For example, set the default service configuration in `- application:didFinishLaunchingWithOptions:`

 *Swift*

     func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        let credentialProvider = AWSCognitoCredentialsProvider(regionType: .USEast1, identityPoolId: "YourIdentityPoolId")
        let configuration = AWSServiceConfiguration(region: .USWest2, credentialsProvider: credentialProvider)
        AWSIoT.register(with: configuration!, forKey: "USWest2IoT")
 
        return true
    }

 *Objective-C*

     - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
         AWSCognitoCredentialsProvider *credentialsProvider = [[AWSCognitoCredentialsProvider alloc] initWithRegionType:AWSRegionUSEast1
                                                                                                         identityPoolId:@"YourIdentityPoolId"];
         AWSServiceConfiguration *configuration = [[AWSServiceConfiguration alloc] initWithRegion:AWSRegionUSWest2
                                                                              credentialsProvider:credentialsProvider];

         [AWSIoT registerIoTWithConfiguration:configuration forKey:@"USWest2IoT"];

         return YES;
     }

 Then call the following to get the service client:

 *Swift*

     let IoT = AWSIoT(forKey: "USWest2IoT")

 *Objective-C*

     AWSIoT *IoT = [AWSIoT IoTForKey:@"USWest2IoT"];

 @warning After calling this method, do not modify the configuration object. It may cause unspecified behaviors.

 @param configuration A service configuration object.
 @param key           A string to identify the service client.
 */
+ (void)registerIoTWithConfiguration:(AWSServiceConfiguration *)configuration forKey:(NSString *)key;

/**
 Retrieves the service client associated with the key. You need to call `+ registerIoTWithConfiguration:forKey:` before invoking this method.

 For example, set the default service configuration in `- application:didFinishLaunchingWithOptions:`

 *Swift*

     func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        let credentialProvider = AWSCognitoCredentialsProvider(regionType: .USEast1, identityPoolId: "YourIdentityPoolId")
        let configuration = AWSServiceConfiguration(region: .USWest2, credentialsProvider: credentialProvider)
        AWSIoT.register(with: configuration!, forKey: "USWest2IoT")
 
        return true
    }

 *Objective-C*

     - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
         AWSCognitoCredentialsProvider *credentialsProvider = [[AWSCognitoCredentialsProvider alloc] initWithRegionType:AWSRegionUSEast1
                                                                                                         identityPoolId:@"YourIdentityPoolId"];
         AWSServiceConfiguration *configuration = [[AWSServiceConfiguration alloc] initWithRegion:AWSRegionUSWest2
                                                                              credentialsProvider:credentialsProvider];

         [AWSIoT registerIoTWithConfiguration:configuration forKey:@"USWest2IoT"];

         return YES;
     }

 Then call the following to get the service client:

 *Swift*

     let IoT = AWSIoT(forKey: "USWest2IoT")

 *Objective-C*

     AWSIoT *IoT = [AWSIoT IoTForKey:@"USWest2IoT"];

 @param key A string to identify the service client.

 @return An instance of the service client.
 */
+ (instancetype)IoTForKey:(NSString *)key;

/**
 Removes the service client associated with the key and release it.
 
 @warning Before calling this method, make sure no method is running on this client.
 
 @param key A string to identify the service client.
 */
+ (void)removeIoTForKey:(NSString *)key;

/**
 <p>Accepts a pending certificate transfer. The default state of the certificate is INACTIVE.</p><p>To check for pending certificate transfers, call <a>ListCertificates</a> to enumerate your certificates.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">AcceptCertificateTransfer</a> action.</p>
 
 @param request A container for the necessary parameters to execute the AcceptCertificateTransfer service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorTransferAlreadyCompleted`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTAcceptCertificateTransferRequest
 */
- (AWSTask *)acceptCertificateTransfer:(AWSIoTAcceptCertificateTransferRequest *)request;

/**
 <p>Accepts a pending certificate transfer. The default state of the certificate is INACTIVE.</p><p>To check for pending certificate transfers, call <a>ListCertificates</a> to enumerate your certificates.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">AcceptCertificateTransfer</a> action.</p>
 
 @param request A container for the necessary parameters to execute the AcceptCertificateTransfer service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorTransferAlreadyCompleted`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTAcceptCertificateTransferRequest
 */
- (void)acceptCertificateTransfer:(AWSIoTAcceptCertificateTransferRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Adds a thing to a billing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">AddThingToBillingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the AddThingToBillingGroup service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTAddThingToBillingGroupResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTAddThingToBillingGroupRequest
 @see AWSIoTAddThingToBillingGroupResponse
 */
- (AWSTask<AWSIoTAddThingToBillingGroupResponse *> *)addThingToBillingGroup:(AWSIoTAddThingToBillingGroupRequest *)request;

/**
 <p>Adds a thing to a billing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">AddThingToBillingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the AddThingToBillingGroup service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTAddThingToBillingGroupRequest
 @see AWSIoTAddThingToBillingGroupResponse
 */
- (void)addThingToBillingGroup:(AWSIoTAddThingToBillingGroupRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTAddThingToBillingGroupResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Adds a thing to a thing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">AddThingToThingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the AddThingToThingGroup service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTAddThingToThingGroupResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTAddThingToThingGroupRequest
 @see AWSIoTAddThingToThingGroupResponse
 */
- (AWSTask<AWSIoTAddThingToThingGroupResponse *> *)addThingToThingGroup:(AWSIoTAddThingToThingGroupRequest *)request;

/**
 <p>Adds a thing to a thing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">AddThingToThingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the AddThingToThingGroup service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTAddThingToThingGroupRequest
 @see AWSIoTAddThingToThingGroupResponse
 */
- (void)addThingToThingGroup:(AWSIoTAddThingToThingGroupRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTAddThingToThingGroupResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Associates a group with a continuous job. The following criteria must be met: </p><ul><li><p>The job must have been created with the <code>targetSelection</code> field set to "CONTINUOUS".</p></li><li><p>The job status must currently be "IN_PROGRESS".</p></li><li><p>The total number of targets associated with a job must not exceed 100.</p></li></ul><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">AssociateTargetsWithJob</a> action.</p>
 
 @param request A container for the necessary parameters to execute the AssociateTargetsWithJob service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTAssociateTargetsWithJobResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTAssociateTargetsWithJobRequest
 @see AWSIoTAssociateTargetsWithJobResponse
 */
- (AWSTask<AWSIoTAssociateTargetsWithJobResponse *> *)associateTargetsWithJob:(AWSIoTAssociateTargetsWithJobRequest *)request;

/**
 <p>Associates a group with a continuous job. The following criteria must be met: </p><ul><li><p>The job must have been created with the <code>targetSelection</code> field set to "CONTINUOUS".</p></li><li><p>The job status must currently be "IN_PROGRESS".</p></li><li><p>The total number of targets associated with a job must not exceed 100.</p></li></ul><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">AssociateTargetsWithJob</a> action.</p>
 
 @param request A container for the necessary parameters to execute the AssociateTargetsWithJob service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTAssociateTargetsWithJobRequest
 @see AWSIoTAssociateTargetsWithJobResponse
 */
- (void)associateTargetsWithJob:(AWSIoTAssociateTargetsWithJobRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTAssociateTargetsWithJobResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Attaches the specified policy to the specified principal (certificate or other credential).</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">AttachPolicy</a> action.</p>
 
 @param request A container for the necessary parameters to execute the AttachPolicy service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTAttachPolicyRequest
 */
- (AWSTask *)attachPolicy:(AWSIoTAttachPolicyRequest *)request;

/**
 <p>Attaches the specified policy to the specified principal (certificate or other credential).</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">AttachPolicy</a> action.</p>
 
 @param request A container for the necessary parameters to execute the AttachPolicy service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTAttachPolicyRequest
 */
- (void)attachPolicy:(AWSIoTAttachPolicyRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Attaches the specified policy to the specified principal (certificate or other credential).</p><p><b>Note:</b> This action is deprecated and works as expected for backward compatibility, but we won't add enhancements. Use <a>AttachPolicy</a> instead.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">AttachPrincipalPolicy</a> action.</p>
 
 @param request A container for the necessary parameters to execute the AttachPrincipalPolicy service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTAttachPrincipalPolicyRequest
 */
- (AWSTask *)attachPrincipalPolicy:(AWSIoTAttachPrincipalPolicyRequest *)request;

/**
 <p>Attaches the specified policy to the specified principal (certificate or other credential).</p><p><b>Note:</b> This action is deprecated and works as expected for backward compatibility, but we won't add enhancements. Use <a>AttachPolicy</a> instead.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">AttachPrincipalPolicy</a> action.</p>
 
 @param request A container for the necessary parameters to execute the AttachPrincipalPolicy service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTAttachPrincipalPolicyRequest
 */
- (void)attachPrincipalPolicy:(AWSIoTAttachPrincipalPolicyRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Associates a Device Defender security profile with a thing group or this account. Each thing group or account can have up to five security profiles associated with it.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">AttachSecurityProfile</a> action.</p>
 
 @param request A container for the necessary parameters to execute the AttachSecurityProfile service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTAttachSecurityProfileResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorVersionConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTAttachSecurityProfileRequest
 @see AWSIoTAttachSecurityProfileResponse
 */
- (AWSTask<AWSIoTAttachSecurityProfileResponse *> *)attachSecurityProfile:(AWSIoTAttachSecurityProfileRequest *)request;

/**
 <p>Associates a Device Defender security profile with a thing group or this account. Each thing group or account can have up to five security profiles associated with it.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">AttachSecurityProfile</a> action.</p>
 
 @param request A container for the necessary parameters to execute the AttachSecurityProfile service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorVersionConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTAttachSecurityProfileRequest
 @see AWSIoTAttachSecurityProfileResponse
 */
- (void)attachSecurityProfile:(AWSIoTAttachSecurityProfileRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTAttachSecurityProfileResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Attaches the specified principal to the specified thing. A principal can be X.509 certificates, Amazon Cognito identities or federated identities.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">AttachThingPrincipal</a> action.</p>
 
 @param request A container for the necessary parameters to execute the AttachThingPrincipal service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTAttachThingPrincipalResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTAttachThingPrincipalRequest
 @see AWSIoTAttachThingPrincipalResponse
 */
- (AWSTask<AWSIoTAttachThingPrincipalResponse *> *)attachThingPrincipal:(AWSIoTAttachThingPrincipalRequest *)request;

/**
 <p>Attaches the specified principal to the specified thing. A principal can be X.509 certificates, Amazon Cognito identities or federated identities.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">AttachThingPrincipal</a> action.</p>
 
 @param request A container for the necessary parameters to execute the AttachThingPrincipal service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTAttachThingPrincipalRequest
 @see AWSIoTAttachThingPrincipalResponse
 */
- (void)attachThingPrincipal:(AWSIoTAttachThingPrincipalRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTAttachThingPrincipalResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Cancels a mitigation action task that is in progress. If the task is not in progress, an InvalidRequestException occurs.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CancelAuditMitigationActionsTask</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CancelAuditMitigationActionsTask service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCancelAuditMitigationActionsTaskResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCancelAuditMitigationActionsTaskRequest
 @see AWSIoTCancelAuditMitigationActionsTaskResponse
 */
- (AWSTask<AWSIoTCancelAuditMitigationActionsTaskResponse *> *)cancelAuditMitigationActionsTask:(AWSIoTCancelAuditMitigationActionsTaskRequest *)request;

/**
 <p>Cancels a mitigation action task that is in progress. If the task is not in progress, an InvalidRequestException occurs.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CancelAuditMitigationActionsTask</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CancelAuditMitigationActionsTask service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCancelAuditMitigationActionsTaskRequest
 @see AWSIoTCancelAuditMitigationActionsTaskResponse
 */
- (void)cancelAuditMitigationActionsTask:(AWSIoTCancelAuditMitigationActionsTaskRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCancelAuditMitigationActionsTaskResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Cancels an audit that is in progress. The audit can be either scheduled or on demand. If the audit isn't in progress, an "InvalidRequestException" occurs.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CancelAuditTask</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CancelAuditTask service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCancelAuditTaskResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCancelAuditTaskRequest
 @see AWSIoTCancelAuditTaskResponse
 */
- (AWSTask<AWSIoTCancelAuditTaskResponse *> *)cancelAuditTask:(AWSIoTCancelAuditTaskRequest *)request;

/**
 <p>Cancels an audit that is in progress. The audit can be either scheduled or on demand. If the audit isn't in progress, an "InvalidRequestException" occurs.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CancelAuditTask</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CancelAuditTask service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCancelAuditTaskRequest
 @see AWSIoTCancelAuditTaskResponse
 */
- (void)cancelAuditTask:(AWSIoTCancelAuditTaskRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCancelAuditTaskResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Cancels a pending transfer for the specified certificate.</p><p><b>Note</b> Only the transfer source account can use this operation to cancel a transfer. (Transfer destinations can use <a>RejectCertificateTransfer</a> instead.) After transfer, IoT returns the certificate to the source account in the INACTIVE state. After the destination account has accepted the transfer, the transfer cannot be cancelled.</p><p>After a certificate transfer is cancelled, the status of the certificate changes from PENDING_TRANSFER to INACTIVE.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CancelCertificateTransfer</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CancelCertificateTransfer service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorTransferAlreadyCompleted`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCancelCertificateTransferRequest
 */
- (AWSTask *)cancelCertificateTransfer:(AWSIoTCancelCertificateTransferRequest *)request;

/**
 <p>Cancels a pending transfer for the specified certificate.</p><p><b>Note</b> Only the transfer source account can use this operation to cancel a transfer. (Transfer destinations can use <a>RejectCertificateTransfer</a> instead.) After transfer, IoT returns the certificate to the source account in the INACTIVE state. After the destination account has accepted the transfer, the transfer cannot be cancelled.</p><p>After a certificate transfer is cancelled, the status of the certificate changes from PENDING_TRANSFER to INACTIVE.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CancelCertificateTransfer</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CancelCertificateTransfer service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorTransferAlreadyCompleted`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCancelCertificateTransferRequest
 */
- (void)cancelCertificateTransfer:(AWSIoTCancelCertificateTransferRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p> Cancels a Device Defender ML Detect mitigation action. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CancelDetectMitigationActionsTask</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CancelDetectMitigationActionsTask service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCancelDetectMitigationActionsTaskResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCancelDetectMitigationActionsTaskRequest
 @see AWSIoTCancelDetectMitigationActionsTaskResponse
 */
- (AWSTask<AWSIoTCancelDetectMitigationActionsTaskResponse *> *)cancelDetectMitigationActionsTask:(AWSIoTCancelDetectMitigationActionsTaskRequest *)request;

/**
 <p> Cancels a Device Defender ML Detect mitigation action. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CancelDetectMitigationActionsTask</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CancelDetectMitigationActionsTask service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCancelDetectMitigationActionsTaskRequest
 @see AWSIoTCancelDetectMitigationActionsTaskResponse
 */
- (void)cancelDetectMitigationActionsTask:(AWSIoTCancelDetectMitigationActionsTaskRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCancelDetectMitigationActionsTaskResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Cancels a job.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CancelJob</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CancelJob service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCancelJobResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTCancelJobRequest
 @see AWSIoTCancelJobResponse
 */
- (AWSTask<AWSIoTCancelJobResponse *> *)cancelJob:(AWSIoTCancelJobRequest *)request;

/**
 <p>Cancels a job.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CancelJob</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CancelJob service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTCancelJobRequest
 @see AWSIoTCancelJobResponse
 */
- (void)cancelJob:(AWSIoTCancelJobRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCancelJobResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Cancels the execution of a job for a given thing.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CancelJobExecution</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CancelJobExecution service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInvalidStateTransition`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorVersionConflict`.
 
 @see AWSIoTCancelJobExecutionRequest
 */
- (AWSTask *)cancelJobExecution:(AWSIoTCancelJobExecutionRequest *)request;

/**
 <p>Cancels the execution of a job for a given thing.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CancelJobExecution</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CancelJobExecution service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInvalidStateTransition`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorVersionConflict`.
 
 @see AWSIoTCancelJobExecutionRequest
 */
- (void)cancelJobExecution:(AWSIoTCancelJobExecutionRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Clears the default authorizer.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ClearDefaultAuthorizer</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ClearDefaultAuthorizer service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTClearDefaultAuthorizerResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTClearDefaultAuthorizerRequest
 @see AWSIoTClearDefaultAuthorizerResponse
 */
- (AWSTask<AWSIoTClearDefaultAuthorizerResponse *> *)clearDefaultAuthorizer:(AWSIoTClearDefaultAuthorizerRequest *)request;

/**
 <p>Clears the default authorizer.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ClearDefaultAuthorizer</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ClearDefaultAuthorizer service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTClearDefaultAuthorizerRequest
 @see AWSIoTClearDefaultAuthorizerResponse
 */
- (void)clearDefaultAuthorizer:(AWSIoTClearDefaultAuthorizerRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTClearDefaultAuthorizerResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Confirms a topic rule destination. When you create a rule requiring a destination, IoT sends a confirmation message to the endpoint or base address you specify. The message includes a token which you pass back when calling <code>ConfirmTopicRuleDestination</code> to confirm that you own or have access to the endpoint.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ConfirmTopicRuleDestination</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ConfirmTopicRuleDestination service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTConfirmTopicRuleDestinationResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorConflictingResourceUpdate`.
 
 @see AWSIoTConfirmTopicRuleDestinationRequest
 @see AWSIoTConfirmTopicRuleDestinationResponse
 */
- (AWSTask<AWSIoTConfirmTopicRuleDestinationResponse *> *)confirmTopicRuleDestination:(AWSIoTConfirmTopicRuleDestinationRequest *)request;

/**
 <p>Confirms a topic rule destination. When you create a rule requiring a destination, IoT sends a confirmation message to the endpoint or base address you specify. The message includes a token which you pass back when calling <code>ConfirmTopicRuleDestination</code> to confirm that you own or have access to the endpoint.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ConfirmTopicRuleDestination</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ConfirmTopicRuleDestination service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorConflictingResourceUpdate`.
 
 @see AWSIoTConfirmTopicRuleDestinationRequest
 @see AWSIoTConfirmTopicRuleDestinationResponse
 */
- (void)confirmTopicRuleDestination:(AWSIoTConfirmTopicRuleDestinationRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTConfirmTopicRuleDestinationResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p> Creates a Device Defender audit suppression. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateAuditSuppression</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateAuditSuppression service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateAuditSuppressionResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTCreateAuditSuppressionRequest
 @see AWSIoTCreateAuditSuppressionResponse
 */
- (AWSTask<AWSIoTCreateAuditSuppressionResponse *> *)createAuditSuppression:(AWSIoTCreateAuditSuppressionRequest *)request;

/**
 <p> Creates a Device Defender audit suppression. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateAuditSuppression</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateAuditSuppression service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTCreateAuditSuppressionRequest
 @see AWSIoTCreateAuditSuppressionResponse
 */
- (void)createAuditSuppression:(AWSIoTCreateAuditSuppressionRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateAuditSuppressionResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates an authorizer.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateAuthorizer</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateAuthorizer service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateAuthorizerResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateAuthorizerRequest
 @see AWSIoTCreateAuthorizerResponse
 */
- (AWSTask<AWSIoTCreateAuthorizerResponse *> *)createAuthorizer:(AWSIoTCreateAuthorizerRequest *)request;

/**
 <p>Creates an authorizer.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateAuthorizer</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateAuthorizer service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateAuthorizerRequest
 @see AWSIoTCreateAuthorizerResponse
 */
- (void)createAuthorizer:(AWSIoTCreateAuthorizerRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateAuthorizerResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates a billing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateBillingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateBillingGroup service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateBillingGroupResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateBillingGroupRequest
 @see AWSIoTCreateBillingGroupResponse
 */
- (AWSTask<AWSIoTCreateBillingGroupResponse *> *)createBillingGroup:(AWSIoTCreateBillingGroupRequest *)request;

/**
 <p>Creates a billing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateBillingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateBillingGroup service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateBillingGroupRequest
 @see AWSIoTCreateBillingGroupResponse
 */
- (void)createBillingGroup:(AWSIoTCreateBillingGroupRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateBillingGroupResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates an X.509 certificate using the specified certificate signing request.</p><p><b>Note:</b> The CSR must include a public key that is either an RSA key with a length of at least 2048 bits or an ECC key from NIST P-256, NIST P-384, or NIST P-512 curves. For supported certificates, consult <a href="https://docs.aws.amazon.com/iot/latest/developerguide/x509-client-certs.html#x509-cert-algorithms"> Certificate signing algorithms supported by IoT</a>.</p><p><b>Note:</b> Reusing the same certificate signing request (CSR) results in a distinct certificate.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateCertificateFromCsr</a> action.</p><p>You can create multiple certificates in a batch by creating a directory, copying multiple .csr files into that directory, and then specifying that directory on the command line. The following commands show how to create a batch of certificates given a batch of CSRs.</p><p>Assuming a set of CSRs are located inside of the directory my-csr-directory:</p><p>On Linux and OS X, the command is:</p><p>$ ls my-csr-directory/ | xargs -I {} aws iot create-certificate-from-csr --certificate-signing-request file://my-csr-directory/{}</p><p>This command lists all of the CSRs in my-csr-directory and pipes each CSR file name to the aws iot create-certificate-from-csr Amazon Web Services CLI command to create a certificate for the corresponding CSR.</p><p>The aws iot create-certificate-from-csr part of the command can also be run in parallel to speed up the certificate creation process:</p><p>$ ls my-csr-directory/ | xargs -P 10 -I {} aws iot create-certificate-from-csr --certificate-signing-request file://my-csr-directory/{}</p><p>On Windows PowerShell, the command to create certificates for all CSRs in my-csr-directory is:</p><p>&gt; ls -Name my-csr-directory | %{aws iot create-certificate-from-csr --certificate-signing-request file://my-csr-directory/$_}</p><p>On a Windows command prompt, the command to create certificates for all CSRs in my-csr-directory is:</p><p>&gt; forfiles /p my-csr-directory /c "cmd /c aws iot create-certificate-from-csr --certificate-signing-request file://@path"</p>
 
 @param request A container for the necessary parameters to execute the CreateCertificateFromCsr service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateCertificateFromCsrResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateCertificateFromCsrRequest
 @see AWSIoTCreateCertificateFromCsrResponse
 */
- (AWSTask<AWSIoTCreateCertificateFromCsrResponse *> *)createCertificateFromCsr:(AWSIoTCreateCertificateFromCsrRequest *)request;

/**
 <p>Creates an X.509 certificate using the specified certificate signing request.</p><p><b>Note:</b> The CSR must include a public key that is either an RSA key with a length of at least 2048 bits or an ECC key from NIST P-256, NIST P-384, or NIST P-512 curves. For supported certificates, consult <a href="https://docs.aws.amazon.com/iot/latest/developerguide/x509-client-certs.html#x509-cert-algorithms"> Certificate signing algorithms supported by IoT</a>.</p><p><b>Note:</b> Reusing the same certificate signing request (CSR) results in a distinct certificate.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateCertificateFromCsr</a> action.</p><p>You can create multiple certificates in a batch by creating a directory, copying multiple .csr files into that directory, and then specifying that directory on the command line. The following commands show how to create a batch of certificates given a batch of CSRs.</p><p>Assuming a set of CSRs are located inside of the directory my-csr-directory:</p><p>On Linux and OS X, the command is:</p><p>$ ls my-csr-directory/ | xargs -I {} aws iot create-certificate-from-csr --certificate-signing-request file://my-csr-directory/{}</p><p>This command lists all of the CSRs in my-csr-directory and pipes each CSR file name to the aws iot create-certificate-from-csr Amazon Web Services CLI command to create a certificate for the corresponding CSR.</p><p>The aws iot create-certificate-from-csr part of the command can also be run in parallel to speed up the certificate creation process:</p><p>$ ls my-csr-directory/ | xargs -P 10 -I {} aws iot create-certificate-from-csr --certificate-signing-request file://my-csr-directory/{}</p><p>On Windows PowerShell, the command to create certificates for all CSRs in my-csr-directory is:</p><p>&gt; ls -Name my-csr-directory | %{aws iot create-certificate-from-csr --certificate-signing-request file://my-csr-directory/$_}</p><p>On a Windows command prompt, the command to create certificates for all CSRs in my-csr-directory is:</p><p>&gt; forfiles /p my-csr-directory /c "cmd /c aws iot create-certificate-from-csr --certificate-signing-request file://@path"</p>
 
 @param request A container for the necessary parameters to execute the CreateCertificateFromCsr service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateCertificateFromCsrRequest
 @see AWSIoTCreateCertificateFromCsrResponse
 */
- (void)createCertificateFromCsr:(AWSIoTCreateCertificateFromCsrRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateCertificateFromCsrResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p> Use this API to define a Custom Metric published by your devices to Device Defender. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateCustomMetric</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateCustomMetric service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateCustomMetricResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateCustomMetricRequest
 @see AWSIoTCreateCustomMetricResponse
 */
- (AWSTask<AWSIoTCreateCustomMetricResponse *> *)createCustomMetric:(AWSIoTCreateCustomMetricRequest *)request;

/**
 <p> Use this API to define a Custom Metric published by your devices to Device Defender. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateCustomMetric</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateCustomMetric service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateCustomMetricRequest
 @see AWSIoTCreateCustomMetricResponse
 */
- (void)createCustomMetric:(AWSIoTCreateCustomMetricRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateCustomMetricResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Create a dimension that you can use to limit the scope of a metric used in a security profile for IoT Device Defender. For example, using a <code>TOPIC_FILTER</code> dimension, you can narrow down the scope of the metric only to MQTT topics whose name match the pattern specified in the dimension.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateDimension</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateDimension service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateDimensionResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTCreateDimensionRequest
 @see AWSIoTCreateDimensionResponse
 */
- (AWSTask<AWSIoTCreateDimensionResponse *> *)createDimension:(AWSIoTCreateDimensionRequest *)request;

/**
 <p>Create a dimension that you can use to limit the scope of a metric used in a security profile for IoT Device Defender. For example, using a <code>TOPIC_FILTER</code> dimension, you can narrow down the scope of the metric only to MQTT topics whose name match the pattern specified in the dimension.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateDimension</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateDimension service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTCreateDimensionRequest
 @see AWSIoTCreateDimensionResponse
 */
- (void)createDimension:(AWSIoTCreateDimensionRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateDimensionResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates a domain configuration.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateDomainConfiguration</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateDomainConfiguration service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateDomainConfigurationResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorLimitExceeded`, `AWSIoTErrorCertificateValidation`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTCreateDomainConfigurationRequest
 @see AWSIoTCreateDomainConfigurationResponse
 */
- (AWSTask<AWSIoTCreateDomainConfigurationResponse *> *)createDomainConfiguration:(AWSIoTCreateDomainConfigurationRequest *)request;

/**
 <p>Creates a domain configuration.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateDomainConfiguration</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateDomainConfiguration service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorLimitExceeded`, `AWSIoTErrorCertificateValidation`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTCreateDomainConfigurationRequest
 @see AWSIoTCreateDomainConfigurationResponse
 */
- (void)createDomainConfiguration:(AWSIoTCreateDomainConfigurationRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateDomainConfigurationResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates a dynamic thing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateDynamicThingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateDynamicThingGroup service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateDynamicThingGroupResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidQuery`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTCreateDynamicThingGroupRequest
 @see AWSIoTCreateDynamicThingGroupResponse
 */
- (AWSTask<AWSIoTCreateDynamicThingGroupResponse *> *)createDynamicThingGroup:(AWSIoTCreateDynamicThingGroupRequest *)request;

/**
 <p>Creates a dynamic thing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateDynamicThingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateDynamicThingGroup service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidQuery`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTCreateDynamicThingGroupRequest
 @see AWSIoTCreateDynamicThingGroupResponse
 */
- (void)createDynamicThingGroup:(AWSIoTCreateDynamicThingGroupRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateDynamicThingGroupResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates a fleet metric.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateFleetMetric</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateFleetMetric service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateFleetMetricResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidQuery`, `AWSIoTErrorInvalidAggregation`, `AWSIoTErrorIndexNotReady`.
 
 @see AWSIoTCreateFleetMetricRequest
 @see AWSIoTCreateFleetMetricResponse
 */
- (AWSTask<AWSIoTCreateFleetMetricResponse *> *)createFleetMetric:(AWSIoTCreateFleetMetricRequest *)request;

/**
 <p>Creates a fleet metric.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateFleetMetric</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateFleetMetric service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidQuery`, `AWSIoTErrorInvalidAggregation`, `AWSIoTErrorIndexNotReady`.
 
 @see AWSIoTCreateFleetMetricRequest
 @see AWSIoTCreateFleetMetricResponse
 */
- (void)createFleetMetric:(AWSIoTCreateFleetMetricRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateFleetMetricResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates a job.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateJob</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateJob service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateJobResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTCreateJobRequest
 @see AWSIoTCreateJobResponse
 */
- (AWSTask<AWSIoTCreateJobResponse *> *)createJob:(AWSIoTCreateJobRequest *)request;

/**
 <p>Creates a job.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateJob</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateJob service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTCreateJobRequest
 @see AWSIoTCreateJobResponse
 */
- (void)createJob:(AWSIoTCreateJobRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateJobResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates a job template.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateJobTemplate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateJobTemplate service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateJobTemplateResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorConflict`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateJobTemplateRequest
 @see AWSIoTCreateJobTemplateResponse
 */
- (AWSTask<AWSIoTCreateJobTemplateResponse *> *)createJobTemplate:(AWSIoTCreateJobTemplateRequest *)request;

/**
 <p>Creates a job template.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateJobTemplate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateJobTemplate service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorConflict`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateJobTemplateRequest
 @see AWSIoTCreateJobTemplateResponse
 */
- (void)createJobTemplate:(AWSIoTCreateJobTemplateRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateJobTemplateResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates a 2048-bit RSA key pair and issues an X.509 certificate using the issued public key. You can also call <code>CreateKeysAndCertificate</code> over MQTT from a device, for more information, see <a href="https://docs.aws.amazon.com/iot/latest/developerguide/provision-wo-cert.html#provision-mqtt-api">Provisioning MQTT API</a>.</p><p><b>Note</b> This is the only time IoT issues the private key for this certificate, so it is important to keep it in a secure location.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateKeysAndCertificate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateKeysAndCertificate service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateKeysAndCertificateResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateKeysAndCertificateRequest
 @see AWSIoTCreateKeysAndCertificateResponse
 */
- (AWSTask<AWSIoTCreateKeysAndCertificateResponse *> *)createKeysAndCertificate:(AWSIoTCreateKeysAndCertificateRequest *)request;

/**
 <p>Creates a 2048-bit RSA key pair and issues an X.509 certificate using the issued public key. You can also call <code>CreateKeysAndCertificate</code> over MQTT from a device, for more information, see <a href="https://docs.aws.amazon.com/iot/latest/developerguide/provision-wo-cert.html#provision-mqtt-api">Provisioning MQTT API</a>.</p><p><b>Note</b> This is the only time IoT issues the private key for this certificate, so it is important to keep it in a secure location.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateKeysAndCertificate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateKeysAndCertificate service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateKeysAndCertificateRequest
 @see AWSIoTCreateKeysAndCertificateResponse
 */
- (void)createKeysAndCertificate:(AWSIoTCreateKeysAndCertificateRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateKeysAndCertificateResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Defines an action that can be applied to audit findings by using StartAuditMitigationActionsTask. Only certain types of mitigation actions can be applied to specific check names. For more information, see <a href="https://docs.aws.amazon.com/iot/latest/developerguide/device-defender-mitigation-actions.html">Mitigation actions</a>. Each mitigation action can apply only one type of change.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateMitigationAction</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateMitigationAction service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateMitigationActionResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateMitigationActionRequest
 @see AWSIoTCreateMitigationActionResponse
 */
- (AWSTask<AWSIoTCreateMitigationActionResponse *> *)createMitigationAction:(AWSIoTCreateMitigationActionRequest *)request;

/**
 <p>Defines an action that can be applied to audit findings by using StartAuditMitigationActionsTask. Only certain types of mitigation actions can be applied to specific check names. For more information, see <a href="https://docs.aws.amazon.com/iot/latest/developerguide/device-defender-mitigation-actions.html">Mitigation actions</a>. Each mitigation action can apply only one type of change.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateMitigationAction</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateMitigationAction service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateMitigationActionRequest
 @see AWSIoTCreateMitigationActionResponse
 */
- (void)createMitigationAction:(AWSIoTCreateMitigationActionRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateMitigationActionResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates an IoT OTA update on a target group of things or groups.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateOTAUpdate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateOTAUpdate service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateOTAUpdateResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTCreateOTAUpdateRequest
 @see AWSIoTCreateOTAUpdateResponse
 */
- (AWSTask<AWSIoTCreateOTAUpdateResponse *> *)createOTAUpdate:(AWSIoTCreateOTAUpdateRequest *)request;

/**
 <p>Creates an IoT OTA update on a target group of things or groups.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateOTAUpdate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateOTAUpdate service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTCreateOTAUpdateRequest
 @see AWSIoTCreateOTAUpdateResponse
 */
- (void)createOTAUpdate:(AWSIoTCreateOTAUpdateRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateOTAUpdateResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates an IoT policy.</p><p>The created policy is the default version for the policy. This operation creates a policy version with a version identifier of <b>1</b> and sets <b>1</b> as the policy's default version.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreatePolicy</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreatePolicy service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreatePolicyResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorMalformedPolicy`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreatePolicyRequest
 @see AWSIoTCreatePolicyResponse
 */
- (AWSTask<AWSIoTCreatePolicyResponse *> *)createPolicy:(AWSIoTCreatePolicyRequest *)request;

/**
 <p>Creates an IoT policy.</p><p>The created policy is the default version for the policy. This operation creates a policy version with a version identifier of <b>1</b> and sets <b>1</b> as the policy's default version.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreatePolicy</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreatePolicy service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorMalformedPolicy`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreatePolicyRequest
 @see AWSIoTCreatePolicyResponse
 */
- (void)createPolicy:(AWSIoTCreatePolicyRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreatePolicyResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates a new version of the specified IoT policy. To update a policy, create a new policy version. A managed policy can have up to five versions. If the policy has five versions, you must use <a>DeletePolicyVersion</a> to delete an existing version before you create a new one.</p><p>Optionally, you can set the new version as the policy's default version. The default version is the operative version (that is, the version that is in effect for the certificates to which the policy is attached).</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreatePolicyVersion</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreatePolicyVersion service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreatePolicyVersionResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorMalformedPolicy`, `AWSIoTErrorVersionsLimitExceeded`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreatePolicyVersionRequest
 @see AWSIoTCreatePolicyVersionResponse
 */
- (AWSTask<AWSIoTCreatePolicyVersionResponse *> *)createPolicyVersion:(AWSIoTCreatePolicyVersionRequest *)request;

/**
 <p>Creates a new version of the specified IoT policy. To update a policy, create a new policy version. A managed policy can have up to five versions. If the policy has five versions, you must use <a>DeletePolicyVersion</a> to delete an existing version before you create a new one.</p><p>Optionally, you can set the new version as the policy's default version. The default version is the operative version (that is, the version that is in effect for the certificates to which the policy is attached).</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreatePolicyVersion</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreatePolicyVersion service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorMalformedPolicy`, `AWSIoTErrorVersionsLimitExceeded`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreatePolicyVersionRequest
 @see AWSIoTCreatePolicyVersionResponse
 */
- (void)createPolicyVersion:(AWSIoTCreatePolicyVersionRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreatePolicyVersionResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates a provisioning claim.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateProvisioningClaim</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateProvisioningClaim service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateProvisioningClaimResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateProvisioningClaimRequest
 @see AWSIoTCreateProvisioningClaimResponse
 */
- (AWSTask<AWSIoTCreateProvisioningClaimResponse *> *)createProvisioningClaim:(AWSIoTCreateProvisioningClaimRequest *)request;

/**
 <p>Creates a provisioning claim.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateProvisioningClaim</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateProvisioningClaim service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateProvisioningClaimRequest
 @see AWSIoTCreateProvisioningClaimResponse
 */
- (void)createProvisioningClaim:(AWSIoTCreateProvisioningClaimRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateProvisioningClaimResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates a provisioning template.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateProvisioningTemplate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateProvisioningTemplate service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateProvisioningTemplateResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorResourceAlreadyExists`.
 
 @see AWSIoTCreateProvisioningTemplateRequest
 @see AWSIoTCreateProvisioningTemplateResponse
 */
- (AWSTask<AWSIoTCreateProvisioningTemplateResponse *> *)createProvisioningTemplate:(AWSIoTCreateProvisioningTemplateRequest *)request;

/**
 <p>Creates a provisioning template.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateProvisioningTemplate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateProvisioningTemplate service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorResourceAlreadyExists`.
 
 @see AWSIoTCreateProvisioningTemplateRequest
 @see AWSIoTCreateProvisioningTemplateResponse
 */
- (void)createProvisioningTemplate:(AWSIoTCreateProvisioningTemplateRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateProvisioningTemplateResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates a new version of a provisioning template.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateProvisioningTemplateVersion</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateProvisioningTemplateVersion service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateProvisioningTemplateVersionResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorVersionsLimitExceeded`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorConflictingResourceUpdate`.
 
 @see AWSIoTCreateProvisioningTemplateVersionRequest
 @see AWSIoTCreateProvisioningTemplateVersionResponse
 */
- (AWSTask<AWSIoTCreateProvisioningTemplateVersionResponse *> *)createProvisioningTemplateVersion:(AWSIoTCreateProvisioningTemplateVersionRequest *)request;

/**
 <p>Creates a new version of a provisioning template.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateProvisioningTemplateVersion</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateProvisioningTemplateVersion service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorVersionsLimitExceeded`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorConflictingResourceUpdate`.
 
 @see AWSIoTCreateProvisioningTemplateVersionRequest
 @see AWSIoTCreateProvisioningTemplateVersionResponse
 */
- (void)createProvisioningTemplateVersion:(AWSIoTCreateProvisioningTemplateVersionRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateProvisioningTemplateVersionResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates a role alias.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateRoleAlias</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateRoleAlias service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateRoleAliasResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateRoleAliasRequest
 @see AWSIoTCreateRoleAliasResponse
 */
- (AWSTask<AWSIoTCreateRoleAliasResponse *> *)createRoleAlias:(AWSIoTCreateRoleAliasRequest *)request;

/**
 <p>Creates a role alias.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateRoleAlias</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateRoleAlias service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateRoleAliasRequest
 @see AWSIoTCreateRoleAliasResponse
 */
- (void)createRoleAlias:(AWSIoTCreateRoleAliasRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateRoleAliasResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates a scheduled audit that is run at a specified time interval.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateScheduledAudit</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateScheduledAudit service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateScheduledAuditResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTCreateScheduledAuditRequest
 @see AWSIoTCreateScheduledAuditResponse
 */
- (AWSTask<AWSIoTCreateScheduledAuditResponse *> *)createScheduledAudit:(AWSIoTCreateScheduledAuditRequest *)request;

/**
 <p>Creates a scheduled audit that is run at a specified time interval.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateScheduledAudit</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateScheduledAudit service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTCreateScheduledAuditRequest
 @see AWSIoTCreateScheduledAuditResponse
 */
- (void)createScheduledAudit:(AWSIoTCreateScheduledAuditRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateScheduledAuditResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates a Device Defender security profile.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateSecurityProfile</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateSecurityProfile service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateSecurityProfileResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateSecurityProfileRequest
 @see AWSIoTCreateSecurityProfileResponse
 */
- (AWSTask<AWSIoTCreateSecurityProfileResponse *> *)createSecurityProfile:(AWSIoTCreateSecurityProfileRequest *)request;

/**
 <p>Creates a Device Defender security profile.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateSecurityProfile</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateSecurityProfile service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateSecurityProfileRequest
 @see AWSIoTCreateSecurityProfileResponse
 */
- (void)createSecurityProfile:(AWSIoTCreateSecurityProfileRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateSecurityProfileResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates a stream for delivering one or more large files in chunks over MQTT. A stream transports data bytes in chunks or blocks packaged as MQTT messages from a source like S3. You can have one or more files associated with a stream.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateStream</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateStream service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateStreamResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateStreamRequest
 @see AWSIoTCreateStreamResponse
 */
- (AWSTask<AWSIoTCreateStreamResponse *> *)createStream:(AWSIoTCreateStreamRequest *)request;

/**
 <p>Creates a stream for delivering one or more large files in chunks over MQTT. A stream transports data bytes in chunks or blocks packaged as MQTT messages from a source like S3. You can have one or more files associated with a stream.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateStream</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateStream service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateStreamRequest
 @see AWSIoTCreateStreamResponse
 */
- (void)createStream:(AWSIoTCreateStreamRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateStreamResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates a thing record in the registry. If this call is made multiple times using the same thing name and configuration, the call will succeed. If this call is made with the same thing name but different configuration a <code>ResourceAlreadyExistsException</code> is thrown.</p><note><p>This is a control plane operation. See <a href="https://docs.aws.amazon.com/iot/latest/developerguide/iot-authorization.html">Authorization</a> for information about authorizing control plane actions.</p></note><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateThing</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateThing service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateThingResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTCreateThingRequest
 @see AWSIoTCreateThingResponse
 */
- (AWSTask<AWSIoTCreateThingResponse *> *)createThing:(AWSIoTCreateThingRequest *)request;

/**
 <p>Creates a thing record in the registry. If this call is made multiple times using the same thing name and configuration, the call will succeed. If this call is made with the same thing name but different configuration a <code>ResourceAlreadyExistsException</code> is thrown.</p><note><p>This is a control plane operation. See <a href="https://docs.aws.amazon.com/iot/latest/developerguide/iot-authorization.html">Authorization</a> for information about authorizing control plane actions.</p></note><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateThing</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateThing service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTCreateThingRequest
 @see AWSIoTCreateThingResponse
 */
- (void)createThing:(AWSIoTCreateThingRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateThingResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Create a thing group.</p><note><p>This is a control plane operation. See <a href="https://docs.aws.amazon.com/iot/latest/developerguide/iot-authorization.html">Authorization</a> for information about authorizing control plane actions.</p></note><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateThingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateThingGroup service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateThingGroupResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateThingGroupRequest
 @see AWSIoTCreateThingGroupResponse
 */
- (AWSTask<AWSIoTCreateThingGroupResponse *> *)createThingGroup:(AWSIoTCreateThingGroupRequest *)request;

/**
 <p>Create a thing group.</p><note><p>This is a control plane operation. See <a href="https://docs.aws.amazon.com/iot/latest/developerguide/iot-authorization.html">Authorization</a> for information about authorizing control plane actions.</p></note><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateThingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateThingGroup service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTCreateThingGroupRequest
 @see AWSIoTCreateThingGroupResponse
 */
- (void)createThingGroup:(AWSIoTCreateThingGroupRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateThingGroupResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates a new thing type.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateThingType</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateThingType service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateThingTypeResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceAlreadyExists`.
 
 @see AWSIoTCreateThingTypeRequest
 @see AWSIoTCreateThingTypeResponse
 */
- (AWSTask<AWSIoTCreateThingTypeResponse *> *)createThingType:(AWSIoTCreateThingTypeRequest *)request;

/**
 <p>Creates a new thing type.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateThingType</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateThingType service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceAlreadyExists`.
 
 @see AWSIoTCreateThingTypeRequest
 @see AWSIoTCreateThingTypeResponse
 */
- (void)createThingType:(AWSIoTCreateThingTypeRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateThingTypeResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates a rule. Creating rules is an administrator-level action. Any user who has permission to create rules will be able to access data processed by the rule.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateTopicRule</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateTopicRule service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorSqlParse`, `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorConflictingResourceUpdate`.
 
 @see AWSIoTCreateTopicRuleRequest
 */
- (AWSTask *)createTopicRule:(AWSIoTCreateTopicRuleRequest *)request;

/**
 <p>Creates a rule. Creating rules is an administrator-level action. Any user who has permission to create rules will be able to access data processed by the rule.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateTopicRule</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateTopicRule service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorSqlParse`, `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorConflictingResourceUpdate`.
 
 @see AWSIoTCreateTopicRuleRequest
 */
- (void)createTopicRule:(AWSIoTCreateTopicRuleRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Creates a topic rule destination. The destination must be confirmed prior to use.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateTopicRuleDestination</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateTopicRuleDestination service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTCreateTopicRuleDestinationResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorConflictingResourceUpdate`.
 
 @see AWSIoTCreateTopicRuleDestinationRequest
 @see AWSIoTCreateTopicRuleDestinationResponse
 */
- (AWSTask<AWSIoTCreateTopicRuleDestinationResponse *> *)createTopicRuleDestination:(AWSIoTCreateTopicRuleDestinationRequest *)request;

/**
 <p>Creates a topic rule destination. The destination must be confirmed prior to use.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">CreateTopicRuleDestination</a> action.</p>
 
 @param request A container for the necessary parameters to execute the CreateTopicRuleDestination service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorConflictingResourceUpdate`.
 
 @see AWSIoTCreateTopicRuleDestinationRequest
 @see AWSIoTCreateTopicRuleDestinationResponse
 */
- (void)createTopicRuleDestination:(AWSIoTCreateTopicRuleDestinationRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTCreateTopicRuleDestinationResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Restores the default settings for Device Defender audits for this account. Any configuration data you entered is deleted and all audit checks are reset to disabled. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteAccountAuditConfiguration</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteAccountAuditConfiguration service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDeleteAccountAuditConfigurationResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteAccountAuditConfigurationRequest
 @see AWSIoTDeleteAccountAuditConfigurationResponse
 */
- (AWSTask<AWSIoTDeleteAccountAuditConfigurationResponse *> *)deleteAccountAuditConfiguration:(AWSIoTDeleteAccountAuditConfigurationRequest *)request;

/**
 <p>Restores the default settings for Device Defender audits for this account. Any configuration data you entered is deleted and all audit checks are reset to disabled. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteAccountAuditConfiguration</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteAccountAuditConfiguration service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteAccountAuditConfigurationRequest
 @see AWSIoTDeleteAccountAuditConfigurationResponse
 */
- (void)deleteAccountAuditConfiguration:(AWSIoTDeleteAccountAuditConfigurationRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDeleteAccountAuditConfigurationResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p> Deletes a Device Defender audit suppression. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteAuditSuppression</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteAuditSuppression service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDeleteAuditSuppressionResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteAuditSuppressionRequest
 @see AWSIoTDeleteAuditSuppressionResponse
 */
- (AWSTask<AWSIoTDeleteAuditSuppressionResponse *> *)deleteAuditSuppression:(AWSIoTDeleteAuditSuppressionRequest *)request;

/**
 <p> Deletes a Device Defender audit suppression. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteAuditSuppression</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteAuditSuppression service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteAuditSuppressionRequest
 @see AWSIoTDeleteAuditSuppressionResponse
 */
- (void)deleteAuditSuppression:(AWSIoTDeleteAuditSuppressionRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDeleteAuditSuppressionResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Deletes an authorizer.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteAuthorizer</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteAuthorizer service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDeleteAuthorizerResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorDeleteConflict`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteAuthorizerRequest
 @see AWSIoTDeleteAuthorizerResponse
 */
- (AWSTask<AWSIoTDeleteAuthorizerResponse *> *)deleteAuthorizer:(AWSIoTDeleteAuthorizerRequest *)request;

/**
 <p>Deletes an authorizer.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteAuthorizer</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteAuthorizer service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorDeleteConflict`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteAuthorizerRequest
 @see AWSIoTDeleteAuthorizerResponse
 */
- (void)deleteAuthorizer:(AWSIoTDeleteAuthorizerRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDeleteAuthorizerResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Deletes the billing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteBillingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteBillingGroup service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDeleteBillingGroupResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorVersionConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteBillingGroupRequest
 @see AWSIoTDeleteBillingGroupResponse
 */
- (AWSTask<AWSIoTDeleteBillingGroupResponse *> *)deleteBillingGroup:(AWSIoTDeleteBillingGroupRequest *)request;

/**
 <p>Deletes the billing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteBillingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteBillingGroup service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorVersionConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteBillingGroupRequest
 @see AWSIoTDeleteBillingGroupResponse
 */
- (void)deleteBillingGroup:(AWSIoTDeleteBillingGroupRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDeleteBillingGroupResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Deletes a registered CA certificate.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteCACertificate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteCACertificate service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDeleteCACertificateResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorCertificateState`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTDeleteCACertificateRequest
 @see AWSIoTDeleteCACertificateResponse
 */
- (AWSTask<AWSIoTDeleteCACertificateResponse *> *)deleteCACertificate:(AWSIoTDeleteCACertificateRequest *)request;

/**
 <p>Deletes a registered CA certificate.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteCACertificate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteCACertificate service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorCertificateState`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTDeleteCACertificateRequest
 @see AWSIoTDeleteCACertificateResponse
 */
- (void)deleteCACertificate:(AWSIoTDeleteCACertificateRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDeleteCACertificateResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Deletes the specified certificate.</p><p>A certificate cannot be deleted if it has a policy or IoT thing attached to it or if its status is set to ACTIVE. To delete a certificate, first use the <a>DetachPolicy</a> action to detach all policies. Next, use the <a>UpdateCertificate</a> action to set the certificate to the INACTIVE status.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteCertificate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteCertificate service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorCertificateState`, `AWSIoTErrorDeleteConflict`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTDeleteCertificateRequest
 */
- (AWSTask *)deleteCertificate:(AWSIoTDeleteCertificateRequest *)request;

/**
 <p>Deletes the specified certificate.</p><p>A certificate cannot be deleted if it has a policy or IoT thing attached to it or if its status is set to ACTIVE. To delete a certificate, first use the <a>DetachPolicy</a> action to detach all policies. Next, use the <a>UpdateCertificate</a> action to set the certificate to the INACTIVE status.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteCertificate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteCertificate service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorCertificateState`, `AWSIoTErrorDeleteConflict`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTDeleteCertificateRequest
 */
- (void)deleteCertificate:(AWSIoTDeleteCertificateRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p> Deletes a Device Defender detect custom metric. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteCustomMetric</a> action.</p><note><p>Before you can delete a custom metric, you must first remove the custom metric from all security profiles it's a part of. The security profile associated with the custom metric can be found using the <a href="https://docs.aws.amazon.com/iot/latest/apireference/API_ListSecurityProfiles.html">ListSecurityProfiles</a> API with <code>metricName</code> set to your custom metric name.</p></note>
 
 @param request A container for the necessary parameters to execute the DeleteCustomMetric service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDeleteCustomMetricResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteCustomMetricRequest
 @see AWSIoTDeleteCustomMetricResponse
 */
- (AWSTask<AWSIoTDeleteCustomMetricResponse *> *)deleteCustomMetric:(AWSIoTDeleteCustomMetricRequest *)request;

/**
 <p> Deletes a Device Defender detect custom metric. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteCustomMetric</a> action.</p><note><p>Before you can delete a custom metric, you must first remove the custom metric from all security profiles it's a part of. The security profile associated with the custom metric can be found using the <a href="https://docs.aws.amazon.com/iot/latest/apireference/API_ListSecurityProfiles.html">ListSecurityProfiles</a> API with <code>metricName</code> set to your custom metric name.</p></note>
 
 @param request A container for the necessary parameters to execute the DeleteCustomMetric service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteCustomMetricRequest
 @see AWSIoTDeleteCustomMetricResponse
 */
- (void)deleteCustomMetric:(AWSIoTDeleteCustomMetricRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDeleteCustomMetricResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Removes the specified dimension from your Amazon Web Services accounts.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteDimension</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteDimension service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDeleteDimensionResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTDeleteDimensionRequest
 @see AWSIoTDeleteDimensionResponse
 */
- (AWSTask<AWSIoTDeleteDimensionResponse *> *)deleteDimension:(AWSIoTDeleteDimensionRequest *)request;

/**
 <p>Removes the specified dimension from your Amazon Web Services accounts.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteDimension</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteDimension service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTDeleteDimensionRequest
 @see AWSIoTDeleteDimensionResponse
 */
- (void)deleteDimension:(AWSIoTDeleteDimensionRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDeleteDimensionResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Deletes the specified domain configuration.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteDomainConfiguration</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteDomainConfiguration service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDeleteDomainConfigurationResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`.
 
 @see AWSIoTDeleteDomainConfigurationRequest
 @see AWSIoTDeleteDomainConfigurationResponse
 */
- (AWSTask<AWSIoTDeleteDomainConfigurationResponse *> *)deleteDomainConfiguration:(AWSIoTDeleteDomainConfigurationRequest *)request;

/**
 <p>Deletes the specified domain configuration.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteDomainConfiguration</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteDomainConfiguration service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`.
 
 @see AWSIoTDeleteDomainConfigurationRequest
 @see AWSIoTDeleteDomainConfigurationResponse
 */
- (void)deleteDomainConfiguration:(AWSIoTDeleteDomainConfigurationRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDeleteDomainConfigurationResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Deletes a dynamic thing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteDynamicThingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteDynamicThingGroup service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDeleteDynamicThingGroupResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorVersionConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteDynamicThingGroupRequest
 @see AWSIoTDeleteDynamicThingGroupResponse
 */
- (AWSTask<AWSIoTDeleteDynamicThingGroupResponse *> *)deleteDynamicThingGroup:(AWSIoTDeleteDynamicThingGroupRequest *)request;

/**
 <p>Deletes a dynamic thing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteDynamicThingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteDynamicThingGroup service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorVersionConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteDynamicThingGroupRequest
 @see AWSIoTDeleteDynamicThingGroupResponse
 */
- (void)deleteDynamicThingGroup:(AWSIoTDeleteDynamicThingGroupRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDeleteDynamicThingGroupResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Deletes the specified fleet metric. Returns successfully with no error if the deletion is successful or you specify a fleet metric that doesn't exist.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteFleetMetric</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteFleetMetric service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorVersionConflict`.
 
 @see AWSIoTDeleteFleetMetricRequest
 */
- (AWSTask *)deleteFleetMetric:(AWSIoTDeleteFleetMetricRequest *)request;

/**
 <p>Deletes the specified fleet metric. Returns successfully with no error if the deletion is successful or you specify a fleet metric that doesn't exist.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteFleetMetric</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteFleetMetric service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorVersionConflict`.
 
 @see AWSIoTDeleteFleetMetricRequest
 */
- (void)deleteFleetMetric:(AWSIoTDeleteFleetMetricRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Deletes a job and its related job executions.</p><p>Deleting a job may take time, depending on the number of job executions created for the job and various other factors. While the job is being deleted, the status of the job will be shown as "DELETION_IN_PROGRESS". Attempting to delete or cancel a job whose status is already "DELETION_IN_PROGRESS" will result in an error.</p><p>Only 10 jobs may have status "DELETION_IN_PROGRESS" at the same time, or a LimitExceededException will occur.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteJob</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteJob service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInvalidStateTransition`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTDeleteJobRequest
 */
- (AWSTask *)deleteJob:(AWSIoTDeleteJobRequest *)request;

/**
 <p>Deletes a job and its related job executions.</p><p>Deleting a job may take time, depending on the number of job executions created for the job and various other factors. While the job is being deleted, the status of the job will be shown as "DELETION_IN_PROGRESS". Attempting to delete or cancel a job whose status is already "DELETION_IN_PROGRESS" will result in an error.</p><p>Only 10 jobs may have status "DELETION_IN_PROGRESS" at the same time, or a LimitExceededException will occur.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteJob</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteJob service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInvalidStateTransition`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTDeleteJobRequest
 */
- (void)deleteJob:(AWSIoTDeleteJobRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Deletes a job execution.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteJobExecution</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteJobExecution service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInvalidStateTransition`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTDeleteJobExecutionRequest
 */
- (AWSTask *)deleteJobExecution:(AWSIoTDeleteJobExecutionRequest *)request;

/**
 <p>Deletes a job execution.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteJobExecution</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteJobExecution service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInvalidStateTransition`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTDeleteJobExecutionRequest
 */
- (void)deleteJobExecution:(AWSIoTDeleteJobExecutionRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Deletes the specified job template.</p>
 
 @param request A container for the necessary parameters to execute the DeleteJobTemplate service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteJobTemplateRequest
 */
- (AWSTask *)deleteJobTemplate:(AWSIoTDeleteJobTemplateRequest *)request;

/**
 <p>Deletes the specified job template.</p>
 
 @param request A container for the necessary parameters to execute the DeleteJobTemplate service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteJobTemplateRequest
 */
- (void)deleteJobTemplate:(AWSIoTDeleteJobTemplateRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Deletes a defined mitigation action from your Amazon Web Services accounts.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteMitigationAction</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteMitigationAction service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDeleteMitigationActionResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteMitigationActionRequest
 @see AWSIoTDeleteMitigationActionResponse
 */
- (AWSTask<AWSIoTDeleteMitigationActionResponse *> *)deleteMitigationAction:(AWSIoTDeleteMitigationActionRequest *)request;

/**
 <p>Deletes a defined mitigation action from your Amazon Web Services accounts.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteMitigationAction</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteMitigationAction service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteMitigationActionRequest
 @see AWSIoTDeleteMitigationActionResponse
 */
- (void)deleteMitigationAction:(AWSIoTDeleteMitigationActionRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDeleteMitigationActionResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Delete an OTA update.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteOTAUpdate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteOTAUpdate service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDeleteOTAUpdateResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorVersionConflict`.
 
 @see AWSIoTDeleteOTAUpdateRequest
 @see AWSIoTDeleteOTAUpdateResponse
 */
- (AWSTask<AWSIoTDeleteOTAUpdateResponse *> *)deleteOTAUpdate:(AWSIoTDeleteOTAUpdateRequest *)request;

/**
 <p>Delete an OTA update.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteOTAUpdate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteOTAUpdate service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorVersionConflict`.
 
 @see AWSIoTDeleteOTAUpdateRequest
 @see AWSIoTDeleteOTAUpdateResponse
 */
- (void)deleteOTAUpdate:(AWSIoTDeleteOTAUpdateRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDeleteOTAUpdateResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Deletes the specified policy.</p><p>A policy cannot be deleted if it has non-default versions or it is attached to any certificate.</p><p>To delete a policy, use the <a>DeletePolicyVersion</a> action to delete all non-default versions of the policy; use the <a>DetachPolicy</a> action to detach the policy from any certificate; and then use the DeletePolicy action to delete the policy.</p><p>When a policy is deleted using DeletePolicy, its default version is deleted with it.</p><note><p>Because of the distributed nature of Amazon Web Services, it can take up to five minutes after a policy is detached before it's ready to be deleted.</p></note><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeletePolicy</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeletePolicy service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorDeleteConflict`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeletePolicyRequest
 */
- (AWSTask *)deletePolicy:(AWSIoTDeletePolicyRequest *)request;

/**
 <p>Deletes the specified policy.</p><p>A policy cannot be deleted if it has non-default versions or it is attached to any certificate.</p><p>To delete a policy, use the <a>DeletePolicyVersion</a> action to delete all non-default versions of the policy; use the <a>DetachPolicy</a> action to detach the policy from any certificate; and then use the DeletePolicy action to delete the policy.</p><p>When a policy is deleted using DeletePolicy, its default version is deleted with it.</p><note><p>Because of the distributed nature of Amazon Web Services, it can take up to five minutes after a policy is detached before it's ready to be deleted.</p></note><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeletePolicy</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeletePolicy service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorDeleteConflict`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeletePolicyRequest
 */
- (void)deletePolicy:(AWSIoTDeletePolicyRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Deletes the specified version of the specified policy. You cannot delete the default version of a policy using this action. To delete the default version of a policy, use <a>DeletePolicy</a>. To find out which version of a policy is marked as the default version, use ListPolicyVersions.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeletePolicyVersion</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeletePolicyVersion service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorDeleteConflict`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeletePolicyVersionRequest
 */
- (AWSTask *)deletePolicyVersion:(AWSIoTDeletePolicyVersionRequest *)request;

/**
 <p>Deletes the specified version of the specified policy. You cannot delete the default version of a policy using this action. To delete the default version of a policy, use <a>DeletePolicy</a>. To find out which version of a policy is marked as the default version, use ListPolicyVersions.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeletePolicyVersion</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeletePolicyVersion service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorDeleteConflict`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeletePolicyVersionRequest
 */
- (void)deletePolicyVersion:(AWSIoTDeletePolicyVersionRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Deletes a provisioning template.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteProvisioningTemplate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteProvisioningTemplate service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDeleteProvisioningTemplateResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorDeleteConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorConflictingResourceUpdate`, `AWSIoTErrorUnauthorized`.
 
 @see AWSIoTDeleteProvisioningTemplateRequest
 @see AWSIoTDeleteProvisioningTemplateResponse
 */
- (AWSTask<AWSIoTDeleteProvisioningTemplateResponse *> *)deleteProvisioningTemplate:(AWSIoTDeleteProvisioningTemplateRequest *)request;

/**
 <p>Deletes a provisioning template.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteProvisioningTemplate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteProvisioningTemplate service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorDeleteConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorConflictingResourceUpdate`, `AWSIoTErrorUnauthorized`.
 
 @see AWSIoTDeleteProvisioningTemplateRequest
 @see AWSIoTDeleteProvisioningTemplateResponse
 */
- (void)deleteProvisioningTemplate:(AWSIoTDeleteProvisioningTemplateRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDeleteProvisioningTemplateResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Deletes a provisioning template version.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteProvisioningTemplateVersion</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteProvisioningTemplateVersion service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDeleteProvisioningTemplateVersionResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorConflictingResourceUpdate`, `AWSIoTErrorDeleteConflict`.
 
 @see AWSIoTDeleteProvisioningTemplateVersionRequest
 @see AWSIoTDeleteProvisioningTemplateVersionResponse
 */
- (AWSTask<AWSIoTDeleteProvisioningTemplateVersionResponse *> *)deleteProvisioningTemplateVersion:(AWSIoTDeleteProvisioningTemplateVersionRequest *)request;

/**
 <p>Deletes a provisioning template version.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteProvisioningTemplateVersion</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteProvisioningTemplateVersion service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorConflictingResourceUpdate`, `AWSIoTErrorDeleteConflict`.
 
 @see AWSIoTDeleteProvisioningTemplateVersionRequest
 @see AWSIoTDeleteProvisioningTemplateVersionResponse
 */
- (void)deleteProvisioningTemplateVersion:(AWSIoTDeleteProvisioningTemplateVersionRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDeleteProvisioningTemplateVersionResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Deletes a CA certificate registration code.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteRegistrationCode</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteRegistrationCode service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDeleteRegistrationCodeResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorThrottling`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteRegistrationCodeRequest
 @see AWSIoTDeleteRegistrationCodeResponse
 */
- (AWSTask<AWSIoTDeleteRegistrationCodeResponse *> *)deleteRegistrationCode:(AWSIoTDeleteRegistrationCodeRequest *)request;

/**
 <p>Deletes a CA certificate registration code.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteRegistrationCode</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteRegistrationCode service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorThrottling`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteRegistrationCodeRequest
 @see AWSIoTDeleteRegistrationCodeResponse
 */
- (void)deleteRegistrationCode:(AWSIoTDeleteRegistrationCodeRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDeleteRegistrationCodeResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Deletes a role alias</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteRoleAlias</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteRoleAlias service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDeleteRoleAliasResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorDeleteConflict`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTDeleteRoleAliasRequest
 @see AWSIoTDeleteRoleAliasResponse
 */
- (AWSTask<AWSIoTDeleteRoleAliasResponse *> *)deleteRoleAlias:(AWSIoTDeleteRoleAliasRequest *)request;

/**
 <p>Deletes a role alias</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteRoleAlias</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteRoleAlias service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorDeleteConflict`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTDeleteRoleAliasRequest
 @see AWSIoTDeleteRoleAliasResponse
 */
- (void)deleteRoleAlias:(AWSIoTDeleteRoleAliasRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDeleteRoleAliasResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Deletes a scheduled audit.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteScheduledAudit</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteScheduledAudit service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDeleteScheduledAuditResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteScheduledAuditRequest
 @see AWSIoTDeleteScheduledAuditResponse
 */
- (AWSTask<AWSIoTDeleteScheduledAuditResponse *> *)deleteScheduledAudit:(AWSIoTDeleteScheduledAuditRequest *)request;

/**
 <p>Deletes a scheduled audit.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteScheduledAudit</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteScheduledAudit service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteScheduledAuditRequest
 @see AWSIoTDeleteScheduledAuditResponse
 */
- (void)deleteScheduledAudit:(AWSIoTDeleteScheduledAuditRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDeleteScheduledAuditResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Deletes a Device Defender security profile.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteSecurityProfile</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteSecurityProfile service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDeleteSecurityProfileResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorVersionConflict`.
 
 @see AWSIoTDeleteSecurityProfileRequest
 @see AWSIoTDeleteSecurityProfileResponse
 */
- (AWSTask<AWSIoTDeleteSecurityProfileResponse *> *)deleteSecurityProfile:(AWSIoTDeleteSecurityProfileRequest *)request;

/**
 <p>Deletes a Device Defender security profile.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteSecurityProfile</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteSecurityProfile service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorVersionConflict`.
 
 @see AWSIoTDeleteSecurityProfileRequest
 @see AWSIoTDeleteSecurityProfileResponse
 */
- (void)deleteSecurityProfile:(AWSIoTDeleteSecurityProfileRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDeleteSecurityProfileResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Deletes a stream.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteStream</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteStream service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDeleteStreamResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorDeleteConflict`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteStreamRequest
 @see AWSIoTDeleteStreamResponse
 */
- (AWSTask<AWSIoTDeleteStreamResponse *> *)deleteStream:(AWSIoTDeleteStreamRequest *)request;

/**
 <p>Deletes a stream.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteStream</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteStream service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorDeleteConflict`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteStreamRequest
 @see AWSIoTDeleteStreamResponse
 */
- (void)deleteStream:(AWSIoTDeleteStreamRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDeleteStreamResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Deletes the specified thing. Returns successfully with no error if the deletion is successful or you specify a thing that doesn't exist.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteThing</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteThing service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDeleteThingResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorVersionConflict`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteThingRequest
 @see AWSIoTDeleteThingResponse
 */
- (AWSTask<AWSIoTDeleteThingResponse *> *)deleteThing:(AWSIoTDeleteThingRequest *)request;

/**
 <p>Deletes the specified thing. Returns successfully with no error if the deletion is successful or you specify a thing that doesn't exist.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteThing</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteThing service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorVersionConflict`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteThingRequest
 @see AWSIoTDeleteThingResponse
 */
- (void)deleteThing:(AWSIoTDeleteThingRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDeleteThingResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Deletes a thing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteThingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteThingGroup service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDeleteThingGroupResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorVersionConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteThingGroupRequest
 @see AWSIoTDeleteThingGroupResponse
 */
- (AWSTask<AWSIoTDeleteThingGroupResponse *> *)deleteThingGroup:(AWSIoTDeleteThingGroupRequest *)request;

/**
 <p>Deletes a thing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteThingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteThingGroup service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorVersionConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteThingGroupRequest
 @see AWSIoTDeleteThingGroupResponse
 */
- (void)deleteThingGroup:(AWSIoTDeleteThingGroupRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDeleteThingGroupResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Deletes the specified thing type. You cannot delete a thing type if it has things associated with it. To delete a thing type, first mark it as deprecated by calling <a>DeprecateThingType</a>, then remove any associated things by calling <a>UpdateThing</a> to change the thing type on any associated thing, and finally use <a>DeleteThingType</a> to delete the thing type.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteThingType</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteThingType service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDeleteThingTypeResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteThingTypeRequest
 @see AWSIoTDeleteThingTypeResponse
 */
- (AWSTask<AWSIoTDeleteThingTypeResponse *> *)deleteThingType:(AWSIoTDeleteThingTypeRequest *)request;

/**
 <p>Deletes the specified thing type. You cannot delete a thing type if it has things associated with it. To delete a thing type, first mark it as deprecated by calling <a>DeprecateThingType</a>, then remove any associated things by calling <a>UpdateThing</a> to change the thing type on any associated thing, and finally use <a>DeleteThingType</a> to delete the thing type.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteThingType</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteThingType service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeleteThingTypeRequest
 @see AWSIoTDeleteThingTypeResponse
 */
- (void)deleteThingType:(AWSIoTDeleteThingTypeRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDeleteThingTypeResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Deletes the rule.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteTopicRule</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteTopicRule service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorConflictingResourceUpdate`.
 
 @see AWSIoTDeleteTopicRuleRequest
 */
- (AWSTask *)deleteTopicRule:(AWSIoTDeleteTopicRuleRequest *)request;

/**
 <p>Deletes the rule.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteTopicRule</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteTopicRule service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorConflictingResourceUpdate`.
 
 @see AWSIoTDeleteTopicRuleRequest
 */
- (void)deleteTopicRule:(AWSIoTDeleteTopicRuleRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Deletes a topic rule destination.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteTopicRuleDestination</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteTopicRuleDestination service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDeleteTopicRuleDestinationResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorConflictingResourceUpdate`.
 
 @see AWSIoTDeleteTopicRuleDestinationRequest
 @see AWSIoTDeleteTopicRuleDestinationResponse
 */
- (AWSTask<AWSIoTDeleteTopicRuleDestinationResponse *> *)deleteTopicRuleDestination:(AWSIoTDeleteTopicRuleDestinationRequest *)request;

/**
 <p>Deletes a topic rule destination.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteTopicRuleDestination</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteTopicRuleDestination service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorConflictingResourceUpdate`.
 
 @see AWSIoTDeleteTopicRuleDestinationRequest
 @see AWSIoTDeleteTopicRuleDestinationResponse
 */
- (void)deleteTopicRuleDestination:(AWSIoTDeleteTopicRuleDestinationRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDeleteTopicRuleDestinationResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Deletes a logging level.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteV2LoggingLevel</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteV2LoggingLevel service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTDeleteV2LoggingLevelRequest
 */
- (AWSTask *)deleteV2LoggingLevel:(AWSIoTDeleteV2LoggingLevelRequest *)request;

/**
 <p>Deletes a logging level.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeleteV2LoggingLevel</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeleteV2LoggingLevel service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTDeleteV2LoggingLevelRequest
 */
- (void)deleteV2LoggingLevel:(AWSIoTDeleteV2LoggingLevelRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Deprecates a thing type. You can not associate new things with deprecated thing type.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeprecateThingType</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeprecateThingType service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDeprecateThingTypeResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeprecateThingTypeRequest
 @see AWSIoTDeprecateThingTypeResponse
 */
- (AWSTask<AWSIoTDeprecateThingTypeResponse *> *)deprecateThingType:(AWSIoTDeprecateThingTypeRequest *)request;

/**
 <p>Deprecates a thing type. You can not associate new things with deprecated thing type.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DeprecateThingType</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DeprecateThingType service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDeprecateThingTypeRequest
 @see AWSIoTDeprecateThingTypeResponse
 */
- (void)deprecateThingType:(AWSIoTDeprecateThingTypeRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDeprecateThingTypeResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets information about the Device Defender audit settings for this account. Settings include how audit notifications are sent and which audit checks are enabled or disabled.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeAccountAuditConfiguration</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeAccountAuditConfiguration service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeAccountAuditConfigurationResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeAccountAuditConfigurationRequest
 @see AWSIoTDescribeAccountAuditConfigurationResponse
 */
- (AWSTask<AWSIoTDescribeAccountAuditConfigurationResponse *> *)describeAccountAuditConfiguration:(AWSIoTDescribeAccountAuditConfigurationRequest *)request;

/**
 <p>Gets information about the Device Defender audit settings for this account. Settings include how audit notifications are sent and which audit checks are enabled or disabled.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeAccountAuditConfiguration</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeAccountAuditConfiguration service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeAccountAuditConfigurationRequest
 @see AWSIoTDescribeAccountAuditConfigurationResponse
 */
- (void)describeAccountAuditConfiguration:(AWSIoTDescribeAccountAuditConfigurationRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeAccountAuditConfigurationResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets information about a single audit finding. Properties include the reason for noncompliance, the severity of the issue, and the start time when the audit that returned the finding.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeAuditFinding</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeAuditFinding service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeAuditFindingResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeAuditFindingRequest
 @see AWSIoTDescribeAuditFindingResponse
 */
- (AWSTask<AWSIoTDescribeAuditFindingResponse *> *)describeAuditFinding:(AWSIoTDescribeAuditFindingRequest *)request;

/**
 <p>Gets information about a single audit finding. Properties include the reason for noncompliance, the severity of the issue, and the start time when the audit that returned the finding.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeAuditFinding</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeAuditFinding service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeAuditFindingRequest
 @see AWSIoTDescribeAuditFindingResponse
 */
- (void)describeAuditFinding:(AWSIoTDescribeAuditFindingRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeAuditFindingResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets information about an audit mitigation task that is used to apply mitigation actions to a set of audit findings. Properties include the actions being applied, the audit checks to which they're being applied, the task status, and aggregated task statistics.</p>
 
 @param request A container for the necessary parameters to execute the DescribeAuditMitigationActionsTask service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeAuditMitigationActionsTaskResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeAuditMitigationActionsTaskRequest
 @see AWSIoTDescribeAuditMitigationActionsTaskResponse
 */
- (AWSTask<AWSIoTDescribeAuditMitigationActionsTaskResponse *> *)describeAuditMitigationActionsTask:(AWSIoTDescribeAuditMitigationActionsTaskRequest *)request;

/**
 <p>Gets information about an audit mitigation task that is used to apply mitigation actions to a set of audit findings. Properties include the actions being applied, the audit checks to which they're being applied, the task status, and aggregated task statistics.</p>
 
 @param request A container for the necessary parameters to execute the DescribeAuditMitigationActionsTask service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeAuditMitigationActionsTaskRequest
 @see AWSIoTDescribeAuditMitigationActionsTaskResponse
 */
- (void)describeAuditMitigationActionsTask:(AWSIoTDescribeAuditMitigationActionsTaskRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeAuditMitigationActionsTaskResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p> Gets information about a Device Defender audit suppression. </p>
 
 @param request A container for the necessary parameters to execute the DescribeAuditSuppression service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeAuditSuppressionResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeAuditSuppressionRequest
 @see AWSIoTDescribeAuditSuppressionResponse
 */
- (AWSTask<AWSIoTDescribeAuditSuppressionResponse *> *)describeAuditSuppression:(AWSIoTDescribeAuditSuppressionRequest *)request;

/**
 <p> Gets information about a Device Defender audit suppression. </p>
 
 @param request A container for the necessary parameters to execute the DescribeAuditSuppression service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeAuditSuppressionRequest
 @see AWSIoTDescribeAuditSuppressionResponse
 */
- (void)describeAuditSuppression:(AWSIoTDescribeAuditSuppressionRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeAuditSuppressionResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets information about a Device Defender audit.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeAuditTask</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeAuditTask service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeAuditTaskResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeAuditTaskRequest
 @see AWSIoTDescribeAuditTaskResponse
 */
- (AWSTask<AWSIoTDescribeAuditTaskResponse *> *)describeAuditTask:(AWSIoTDescribeAuditTaskRequest *)request;

/**
 <p>Gets information about a Device Defender audit.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeAuditTask</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeAuditTask service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeAuditTaskRequest
 @see AWSIoTDescribeAuditTaskResponse
 */
- (void)describeAuditTask:(AWSIoTDescribeAuditTaskRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeAuditTaskResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Describes an authorizer.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeAuthorizer</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeAuthorizer service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeAuthorizerResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeAuthorizerRequest
 @see AWSIoTDescribeAuthorizerResponse
 */
- (AWSTask<AWSIoTDescribeAuthorizerResponse *> *)describeAuthorizer:(AWSIoTDescribeAuthorizerRequest *)request;

/**
 <p>Describes an authorizer.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeAuthorizer</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeAuthorizer service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeAuthorizerRequest
 @see AWSIoTDescribeAuthorizerResponse
 */
- (void)describeAuthorizer:(AWSIoTDescribeAuthorizerRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeAuthorizerResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Returns information about a billing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeBillingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeBillingGroup service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeBillingGroupResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTDescribeBillingGroupRequest
 @see AWSIoTDescribeBillingGroupResponse
 */
- (AWSTask<AWSIoTDescribeBillingGroupResponse *> *)describeBillingGroup:(AWSIoTDescribeBillingGroupRequest *)request;

/**
 <p>Returns information about a billing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeBillingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeBillingGroup service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTDescribeBillingGroupRequest
 @see AWSIoTDescribeBillingGroupResponse
 */
- (void)describeBillingGroup:(AWSIoTDescribeBillingGroupRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeBillingGroupResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Describes a registered CA certificate.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeCACertificate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeCACertificate service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeCACertificateResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTDescribeCACertificateRequest
 @see AWSIoTDescribeCACertificateResponse
 */
- (AWSTask<AWSIoTDescribeCACertificateResponse *> *)describeCACertificate:(AWSIoTDescribeCACertificateRequest *)request;

/**
 <p>Describes a registered CA certificate.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeCACertificate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeCACertificate service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTDescribeCACertificateRequest
 @see AWSIoTDescribeCACertificateResponse
 */
- (void)describeCACertificate:(AWSIoTDescribeCACertificateRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeCACertificateResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets information about the specified certificate.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeCertificate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeCertificate service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeCertificateResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTDescribeCertificateRequest
 @see AWSIoTDescribeCertificateResponse
 */
- (AWSTask<AWSIoTDescribeCertificateResponse *> *)describeCertificate:(AWSIoTDescribeCertificateRequest *)request;

/**
 <p>Gets information about the specified certificate.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeCertificate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeCertificate service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTDescribeCertificateRequest
 @see AWSIoTDescribeCertificateResponse
 */
- (void)describeCertificate:(AWSIoTDescribeCertificateRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeCertificateResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p> Gets information about a Device Defender detect custom metric. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeCustomMetric</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeCustomMetric service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeCustomMetricResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeCustomMetricRequest
 @see AWSIoTDescribeCustomMetricResponse
 */
- (AWSTask<AWSIoTDescribeCustomMetricResponse *> *)describeCustomMetric:(AWSIoTDescribeCustomMetricRequest *)request;

/**
 <p> Gets information about a Device Defender detect custom metric. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeCustomMetric</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeCustomMetric service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeCustomMetricRequest
 @see AWSIoTDescribeCustomMetricResponse
 */
- (void)describeCustomMetric:(AWSIoTDescribeCustomMetricRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeCustomMetricResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Describes the default authorizer.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeDefaultAuthorizer</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeDefaultAuthorizer service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeDefaultAuthorizerResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeDefaultAuthorizerRequest
 @see AWSIoTDescribeDefaultAuthorizerResponse
 */
- (AWSTask<AWSIoTDescribeDefaultAuthorizerResponse *> *)describeDefaultAuthorizer:(AWSIoTDescribeDefaultAuthorizerRequest *)request;

/**
 <p>Describes the default authorizer.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeDefaultAuthorizer</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeDefaultAuthorizer service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeDefaultAuthorizerRequest
 @see AWSIoTDescribeDefaultAuthorizerResponse
 */
- (void)describeDefaultAuthorizer:(AWSIoTDescribeDefaultAuthorizerRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeDefaultAuthorizerResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p> Gets information about a Device Defender ML Detect mitigation action. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeDetectMitigationActionsTask</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeDetectMitigationActionsTask service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeDetectMitigationActionsTaskResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeDetectMitigationActionsTaskRequest
 @see AWSIoTDescribeDetectMitigationActionsTaskResponse
 */
- (AWSTask<AWSIoTDescribeDetectMitigationActionsTaskResponse *> *)describeDetectMitigationActionsTask:(AWSIoTDescribeDetectMitigationActionsTaskRequest *)request;

/**
 <p> Gets information about a Device Defender ML Detect mitigation action. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeDetectMitigationActionsTask</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeDetectMitigationActionsTask service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeDetectMitigationActionsTaskRequest
 @see AWSIoTDescribeDetectMitigationActionsTaskResponse
 */
- (void)describeDetectMitigationActionsTask:(AWSIoTDescribeDetectMitigationActionsTaskRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeDetectMitigationActionsTaskResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Provides details about a dimension that is defined in your Amazon Web Services accounts.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeDimension</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeDimension service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeDimensionResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTDescribeDimensionRequest
 @see AWSIoTDescribeDimensionResponse
 */
- (AWSTask<AWSIoTDescribeDimensionResponse *> *)describeDimension:(AWSIoTDescribeDimensionRequest *)request;

/**
 <p>Provides details about a dimension that is defined in your Amazon Web Services accounts.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeDimension</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeDimension service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTDescribeDimensionRequest
 @see AWSIoTDescribeDimensionResponse
 */
- (void)describeDimension:(AWSIoTDescribeDimensionRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeDimensionResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets summary information about a domain configuration.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeDomainConfiguration</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeDomainConfiguration service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeDomainConfigurationResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeDomainConfigurationRequest
 @see AWSIoTDescribeDomainConfigurationResponse
 */
- (AWSTask<AWSIoTDescribeDomainConfigurationResponse *> *)describeDomainConfiguration:(AWSIoTDescribeDomainConfigurationRequest *)request;

/**
 <p>Gets summary information about a domain configuration.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeDomainConfiguration</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeDomainConfiguration service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeDomainConfigurationRequest
 @see AWSIoTDescribeDomainConfigurationResponse
 */
- (void)describeDomainConfiguration:(AWSIoTDescribeDomainConfigurationRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeDomainConfigurationResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Returns a unique endpoint specific to the Amazon Web Services account making the call.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeEndpoint</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeEndpoint service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeEndpointResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTDescribeEndpointRequest
 @see AWSIoTDescribeEndpointResponse
 */
- (AWSTask<AWSIoTDescribeEndpointResponse *> *)describeEndpoint:(AWSIoTDescribeEndpointRequest *)request;

/**
 <p>Returns a unique endpoint specific to the Amazon Web Services account making the call.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeEndpoint</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeEndpoint service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTDescribeEndpointRequest
 @see AWSIoTDescribeEndpointResponse
 */
- (void)describeEndpoint:(AWSIoTDescribeEndpointRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeEndpointResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Describes event configurations.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeEventConfigurations</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeEventConfigurations service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeEventConfigurationsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTDescribeEventConfigurationsRequest
 @see AWSIoTDescribeEventConfigurationsResponse
 */
- (AWSTask<AWSIoTDescribeEventConfigurationsResponse *> *)describeEventConfigurations:(AWSIoTDescribeEventConfigurationsRequest *)request;

/**
 <p>Describes event configurations.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeEventConfigurations</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeEventConfigurations service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTDescribeEventConfigurationsRequest
 @see AWSIoTDescribeEventConfigurationsResponse
 */
- (void)describeEventConfigurations:(AWSIoTDescribeEventConfigurationsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeEventConfigurationsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets information about the specified fleet metric.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeFleetMetric</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeFleetMetric service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeFleetMetricResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTDescribeFleetMetricRequest
 @see AWSIoTDescribeFleetMetricResponse
 */
- (AWSTask<AWSIoTDescribeFleetMetricResponse *> *)describeFleetMetric:(AWSIoTDescribeFleetMetricRequest *)request;

/**
 <p>Gets information about the specified fleet metric.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeFleetMetric</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeFleetMetric service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTDescribeFleetMetricRequest
 @see AWSIoTDescribeFleetMetricResponse
 */
- (void)describeFleetMetric:(AWSIoTDescribeFleetMetricRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeFleetMetricResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Describes a search index.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeIndex</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeIndex service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeIndexResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTDescribeIndexRequest
 @see AWSIoTDescribeIndexResponse
 */
- (AWSTask<AWSIoTDescribeIndexResponse *> *)describeIndex:(AWSIoTDescribeIndexRequest *)request;

/**
 <p>Describes a search index.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeIndex</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeIndex service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTDescribeIndexRequest
 @see AWSIoTDescribeIndexResponse
 */
- (void)describeIndex:(AWSIoTDescribeIndexRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeIndexResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Describes a job.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeJob</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeJob service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeJobResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTDescribeJobRequest
 @see AWSIoTDescribeJobResponse
 */
- (AWSTask<AWSIoTDescribeJobResponse *> *)describeJob:(AWSIoTDescribeJobRequest *)request;

/**
 <p>Describes a job.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeJob</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeJob service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTDescribeJobRequest
 @see AWSIoTDescribeJobResponse
 */
- (void)describeJob:(AWSIoTDescribeJobRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeJobResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Describes a job execution.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeJobExecution</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeJobExecution service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeJobExecutionResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTDescribeJobExecutionRequest
 @see AWSIoTDescribeJobExecutionResponse
 */
- (AWSTask<AWSIoTDescribeJobExecutionResponse *> *)describeJobExecution:(AWSIoTDescribeJobExecutionRequest *)request;

/**
 <p>Describes a job execution.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeJobExecution</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeJobExecution service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTDescribeJobExecutionRequest
 @see AWSIoTDescribeJobExecutionResponse
 */
- (void)describeJobExecution:(AWSIoTDescribeJobExecutionRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeJobExecutionResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Returns information about a job template.</p>
 
 @param request A container for the necessary parameters to execute the DescribeJobTemplate service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeJobTemplateResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeJobTemplateRequest
 @see AWSIoTDescribeJobTemplateResponse
 */
- (AWSTask<AWSIoTDescribeJobTemplateResponse *> *)describeJobTemplate:(AWSIoTDescribeJobTemplateRequest *)request;

/**
 <p>Returns information about a job template.</p>
 
 @param request A container for the necessary parameters to execute the DescribeJobTemplate service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeJobTemplateRequest
 @see AWSIoTDescribeJobTemplateResponse
 */
- (void)describeJobTemplate:(AWSIoTDescribeJobTemplateRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeJobTemplateResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>View details of a managed job template.</p>
 
 @param request A container for the necessary parameters to execute the DescribeManagedJobTemplate service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeManagedJobTemplateResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalServer`.
 
 @see AWSIoTDescribeManagedJobTemplateRequest
 @see AWSIoTDescribeManagedJobTemplateResponse
 */
- (AWSTask<AWSIoTDescribeManagedJobTemplateResponse *> *)describeManagedJobTemplate:(AWSIoTDescribeManagedJobTemplateRequest *)request;

/**
 <p>View details of a managed job template.</p>
 
 @param request A container for the necessary parameters to execute the DescribeManagedJobTemplate service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalServer`.
 
 @see AWSIoTDescribeManagedJobTemplateRequest
 @see AWSIoTDescribeManagedJobTemplateResponse
 */
- (void)describeManagedJobTemplate:(AWSIoTDescribeManagedJobTemplateRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeManagedJobTemplateResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets information about a mitigation action.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeMitigationAction</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeMitigationAction service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeMitigationActionResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeMitigationActionRequest
 @see AWSIoTDescribeMitigationActionResponse
 */
- (AWSTask<AWSIoTDescribeMitigationActionResponse *> *)describeMitigationAction:(AWSIoTDescribeMitigationActionRequest *)request;

/**
 <p>Gets information about a mitigation action.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeMitigationAction</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeMitigationAction service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeMitigationActionRequest
 @see AWSIoTDescribeMitigationActionResponse
 */
- (void)describeMitigationAction:(AWSIoTDescribeMitigationActionRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeMitigationActionResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Returns information about a provisioning template.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeProvisioningTemplate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeProvisioningTemplate service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeProvisioningTemplateResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`.
 
 @see AWSIoTDescribeProvisioningTemplateRequest
 @see AWSIoTDescribeProvisioningTemplateResponse
 */
- (AWSTask<AWSIoTDescribeProvisioningTemplateResponse *> *)describeProvisioningTemplate:(AWSIoTDescribeProvisioningTemplateRequest *)request;

/**
 <p>Returns information about a provisioning template.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeProvisioningTemplate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeProvisioningTemplate service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`.
 
 @see AWSIoTDescribeProvisioningTemplateRequest
 @see AWSIoTDescribeProvisioningTemplateResponse
 */
- (void)describeProvisioningTemplate:(AWSIoTDescribeProvisioningTemplateRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeProvisioningTemplateResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Returns information about a provisioning template version.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeProvisioningTemplateVersion</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeProvisioningTemplateVersion service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeProvisioningTemplateVersionResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorUnauthorized`.
 
 @see AWSIoTDescribeProvisioningTemplateVersionRequest
 @see AWSIoTDescribeProvisioningTemplateVersionResponse
 */
- (AWSTask<AWSIoTDescribeProvisioningTemplateVersionResponse *> *)describeProvisioningTemplateVersion:(AWSIoTDescribeProvisioningTemplateVersionRequest *)request;

/**
 <p>Returns information about a provisioning template version.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeProvisioningTemplateVersion</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeProvisioningTemplateVersion service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorUnauthorized`.
 
 @see AWSIoTDescribeProvisioningTemplateVersionRequest
 @see AWSIoTDescribeProvisioningTemplateVersionResponse
 */
- (void)describeProvisioningTemplateVersion:(AWSIoTDescribeProvisioningTemplateVersionRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeProvisioningTemplateVersionResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Describes a role alias.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeRoleAlias</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeRoleAlias service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeRoleAliasResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTDescribeRoleAliasRequest
 @see AWSIoTDescribeRoleAliasResponse
 */
- (AWSTask<AWSIoTDescribeRoleAliasResponse *> *)describeRoleAlias:(AWSIoTDescribeRoleAliasRequest *)request;

/**
 <p>Describes a role alias.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeRoleAlias</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeRoleAlias service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTDescribeRoleAliasRequest
 @see AWSIoTDescribeRoleAliasResponse
 */
- (void)describeRoleAlias:(AWSIoTDescribeRoleAliasRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeRoleAliasResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets information about a scheduled audit.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeScheduledAudit</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeScheduledAudit service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeScheduledAuditResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeScheduledAuditRequest
 @see AWSIoTDescribeScheduledAuditResponse
 */
- (AWSTask<AWSIoTDescribeScheduledAuditResponse *> *)describeScheduledAudit:(AWSIoTDescribeScheduledAuditRequest *)request;

/**
 <p>Gets information about a scheduled audit.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeScheduledAudit</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeScheduledAudit service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeScheduledAuditRequest
 @see AWSIoTDescribeScheduledAuditResponse
 */
- (void)describeScheduledAudit:(AWSIoTDescribeScheduledAuditRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeScheduledAuditResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets information about a Device Defender security profile.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeSecurityProfile</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeSecurityProfile service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeSecurityProfileResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeSecurityProfileRequest
 @see AWSIoTDescribeSecurityProfileResponse
 */
- (AWSTask<AWSIoTDescribeSecurityProfileResponse *> *)describeSecurityProfile:(AWSIoTDescribeSecurityProfileRequest *)request;

/**
 <p>Gets information about a Device Defender security profile.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeSecurityProfile</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeSecurityProfile service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeSecurityProfileRequest
 @see AWSIoTDescribeSecurityProfileResponse
 */
- (void)describeSecurityProfile:(AWSIoTDescribeSecurityProfileRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeSecurityProfileResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets information about a stream.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeStream</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeStream service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeStreamResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeStreamRequest
 @see AWSIoTDescribeStreamResponse
 */
- (AWSTask<AWSIoTDescribeStreamResponse *> *)describeStream:(AWSIoTDescribeStreamRequest *)request;

/**
 <p>Gets information about a stream.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeStream</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeStream service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeStreamRequest
 @see AWSIoTDescribeStreamResponse
 */
- (void)describeStream:(AWSIoTDescribeStreamRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeStreamResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets information about the specified thing.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeThing</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeThing service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeThingResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeThingRequest
 @see AWSIoTDescribeThingResponse
 */
- (AWSTask<AWSIoTDescribeThingResponse *> *)describeThing:(AWSIoTDescribeThingRequest *)request;

/**
 <p>Gets information about the specified thing.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeThing</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeThing service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeThingRequest
 @see AWSIoTDescribeThingResponse
 */
- (void)describeThing:(AWSIoTDescribeThingRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeThingResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Describe a thing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeThingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeThingGroup service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeThingGroupResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTDescribeThingGroupRequest
 @see AWSIoTDescribeThingGroupResponse
 */
- (AWSTask<AWSIoTDescribeThingGroupResponse *> *)describeThingGroup:(AWSIoTDescribeThingGroupRequest *)request;

/**
 <p>Describe a thing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeThingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeThingGroup service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTDescribeThingGroupRequest
 @see AWSIoTDescribeThingGroupResponse
 */
- (void)describeThingGroup:(AWSIoTDescribeThingGroupRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeThingGroupResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Describes a bulk thing provisioning task.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeThingRegistrationTask</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeThingRegistrationTask service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeThingRegistrationTaskResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTDescribeThingRegistrationTaskRequest
 @see AWSIoTDescribeThingRegistrationTaskResponse
 */
- (AWSTask<AWSIoTDescribeThingRegistrationTaskResponse *> *)describeThingRegistrationTask:(AWSIoTDescribeThingRegistrationTaskRequest *)request;

/**
 <p>Describes a bulk thing provisioning task.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeThingRegistrationTask</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeThingRegistrationTask service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTDescribeThingRegistrationTaskRequest
 @see AWSIoTDescribeThingRegistrationTaskResponse
 */
- (void)describeThingRegistrationTask:(AWSIoTDescribeThingRegistrationTaskRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeThingRegistrationTaskResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets information about the specified thing type.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeThingType</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeThingType service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDescribeThingTypeResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeThingTypeRequest
 @see AWSIoTDescribeThingTypeResponse
 */
- (AWSTask<AWSIoTDescribeThingTypeResponse *> *)describeThingType:(AWSIoTDescribeThingTypeRequest *)request;

/**
 <p>Gets information about the specified thing type.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DescribeThingType</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DescribeThingType service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDescribeThingTypeRequest
 @see AWSIoTDescribeThingTypeResponse
 */
- (void)describeThingType:(AWSIoTDescribeThingTypeRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDescribeThingTypeResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Detaches a policy from the specified target.</p><note><p>Because of the distributed nature of Amazon Web Services, it can take up to five minutes after a policy is detached before it's ready to be deleted.</p></note><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DetachPolicy</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DetachPolicy service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTDetachPolicyRequest
 */
- (AWSTask *)detachPolicy:(AWSIoTDetachPolicyRequest *)request;

/**
 <p>Detaches a policy from the specified target.</p><note><p>Because of the distributed nature of Amazon Web Services, it can take up to five minutes after a policy is detached before it's ready to be deleted.</p></note><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DetachPolicy</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DetachPolicy service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTDetachPolicyRequest
 */
- (void)detachPolicy:(AWSIoTDetachPolicyRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Removes the specified policy from the specified certificate.</p><p><b>Note:</b> This action is deprecated and works as expected for backward compatibility, but we won't add enhancements. Use <a>DetachPolicy</a> instead.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DetachPrincipalPolicy</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DetachPrincipalPolicy service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDetachPrincipalPolicyRequest
 */
- (AWSTask *)detachPrincipalPolicy:(AWSIoTDetachPrincipalPolicyRequest *)request;

/**
 <p>Removes the specified policy from the specified certificate.</p><p><b>Note:</b> This action is deprecated and works as expected for backward compatibility, but we won't add enhancements. Use <a>DetachPolicy</a> instead.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DetachPrincipalPolicy</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DetachPrincipalPolicy service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDetachPrincipalPolicyRequest
 */
- (void)detachPrincipalPolicy:(AWSIoTDetachPrincipalPolicyRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Disassociates a Device Defender security profile from a thing group or from this account.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DetachSecurityProfile</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DetachSecurityProfile service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDetachSecurityProfileResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDetachSecurityProfileRequest
 @see AWSIoTDetachSecurityProfileResponse
 */
- (AWSTask<AWSIoTDetachSecurityProfileResponse *> *)detachSecurityProfile:(AWSIoTDetachSecurityProfileRequest *)request;

/**
 <p>Disassociates a Device Defender security profile from a thing group or from this account.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DetachSecurityProfile</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DetachSecurityProfile service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDetachSecurityProfileRequest
 @see AWSIoTDetachSecurityProfileResponse
 */
- (void)detachSecurityProfile:(AWSIoTDetachSecurityProfileRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDetachSecurityProfileResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Detaches the specified principal from the specified thing. A principal can be X.509 certificates, IAM users, groups, and roles, Amazon Cognito identities or federated identities.</p><note><p>This call is asynchronous. It might take several seconds for the detachment to propagate.</p></note><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DetachThingPrincipal</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DetachThingPrincipal service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTDetachThingPrincipalResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDetachThingPrincipalRequest
 @see AWSIoTDetachThingPrincipalResponse
 */
- (AWSTask<AWSIoTDetachThingPrincipalResponse *> *)detachThingPrincipal:(AWSIoTDetachThingPrincipalRequest *)request;

/**
 <p>Detaches the specified principal from the specified thing. A principal can be X.509 certificates, IAM users, groups, and roles, Amazon Cognito identities or federated identities.</p><note><p>This call is asynchronous. It might take several seconds for the detachment to propagate.</p></note><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DetachThingPrincipal</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DetachThingPrincipal service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTDetachThingPrincipalRequest
 @see AWSIoTDetachThingPrincipalResponse
 */
- (void)detachThingPrincipal:(AWSIoTDetachThingPrincipalRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTDetachThingPrincipalResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Disables the rule.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DisableTopicRule</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DisableTopicRule service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorConflictingResourceUpdate`.
 
 @see AWSIoTDisableTopicRuleRequest
 */
- (AWSTask *)disableTopicRule:(AWSIoTDisableTopicRuleRequest *)request;

/**
 <p>Disables the rule.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">DisableTopicRule</a> action.</p>
 
 @param request A container for the necessary parameters to execute the DisableTopicRule service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorConflictingResourceUpdate`.
 
 @see AWSIoTDisableTopicRuleRequest
 */
- (void)disableTopicRule:(AWSIoTDisableTopicRuleRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Enables the rule.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">EnableTopicRule</a> action.</p>
 
 @param request A container for the necessary parameters to execute the EnableTopicRule service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorConflictingResourceUpdate`.
 
 @see AWSIoTEnableTopicRuleRequest
 */
- (AWSTask *)enableTopicRule:(AWSIoTEnableTopicRuleRequest *)request;

/**
 <p>Enables the rule.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">EnableTopicRule</a> action.</p>
 
 @param request A container for the necessary parameters to execute the EnableTopicRule service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorConflictingResourceUpdate`.
 
 @see AWSIoTEnableTopicRuleRequest
 */
- (void)enableTopicRule:(AWSIoTEnableTopicRuleRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p> Returns a Device Defender's ML Detect Security Profile training model's status. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetBehaviorModelTrainingSummaries</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetBehaviorModelTrainingSummaries service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTGetBehaviorModelTrainingSummariesResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTGetBehaviorModelTrainingSummariesRequest
 @see AWSIoTGetBehaviorModelTrainingSummariesResponse
 */
- (AWSTask<AWSIoTGetBehaviorModelTrainingSummariesResponse *> *)getBehaviorModelTrainingSummaries:(AWSIoTGetBehaviorModelTrainingSummariesRequest *)request;

/**
 <p> Returns a Device Defender's ML Detect Security Profile training model's status. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetBehaviorModelTrainingSummaries</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetBehaviorModelTrainingSummaries service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTGetBehaviorModelTrainingSummariesRequest
 @see AWSIoTGetBehaviorModelTrainingSummariesResponse
 */
- (void)getBehaviorModelTrainingSummaries:(AWSIoTGetBehaviorModelTrainingSummariesRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTGetBehaviorModelTrainingSummariesResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Aggregates on indexed data with search queries pertaining to particular fields. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetBucketsAggregation</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetBucketsAggregation service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTGetBucketsAggregationResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidQuery`, `AWSIoTErrorInvalidAggregation`, `AWSIoTErrorIndexNotReady`.
 
 @see AWSIoTGetBucketsAggregationRequest
 @see AWSIoTGetBucketsAggregationResponse
 */
- (AWSTask<AWSIoTGetBucketsAggregationResponse *> *)getBucketsAggregation:(AWSIoTGetBucketsAggregationRequest *)request;

/**
 <p>Aggregates on indexed data with search queries pertaining to particular fields. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetBucketsAggregation</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetBucketsAggregation service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidQuery`, `AWSIoTErrorInvalidAggregation`, `AWSIoTErrorIndexNotReady`.
 
 @see AWSIoTGetBucketsAggregationRequest
 @see AWSIoTGetBucketsAggregationResponse
 */
- (void)getBucketsAggregation:(AWSIoTGetBucketsAggregationRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTGetBucketsAggregationResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Returns the approximate count of unique values that match the query.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetCardinality</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetCardinality service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTGetCardinalityResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidQuery`, `AWSIoTErrorInvalidAggregation`, `AWSIoTErrorIndexNotReady`.
 
 @see AWSIoTGetCardinalityRequest
 @see AWSIoTGetCardinalityResponse
 */
- (AWSTask<AWSIoTGetCardinalityResponse *> *)getCardinality:(AWSIoTGetCardinalityRequest *)request;

/**
 <p>Returns the approximate count of unique values that match the query.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetCardinality</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetCardinality service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidQuery`, `AWSIoTErrorInvalidAggregation`, `AWSIoTErrorIndexNotReady`.
 
 @see AWSIoTGetCardinalityRequest
 @see AWSIoTGetCardinalityResponse
 */
- (void)getCardinality:(AWSIoTGetCardinalityRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTGetCardinalityResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets a list of the policies that have an effect on the authorization behavior of the specified device when it connects to the IoT device gateway.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetEffectivePolicies</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetEffectivePolicies service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTGetEffectivePoliciesResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTGetEffectivePoliciesRequest
 @see AWSIoTGetEffectivePoliciesResponse
 */
- (AWSTask<AWSIoTGetEffectivePoliciesResponse *> *)getEffectivePolicies:(AWSIoTGetEffectivePoliciesRequest *)request;

/**
 <p>Gets a list of the policies that have an effect on the authorization behavior of the specified device when it connects to the IoT device gateway.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetEffectivePolicies</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetEffectivePolicies service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTGetEffectivePoliciesRequest
 @see AWSIoTGetEffectivePoliciesResponse
 */
- (void)getEffectivePolicies:(AWSIoTGetEffectivePoliciesRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTGetEffectivePoliciesResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets the indexing configuration.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetIndexingConfiguration</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetIndexingConfiguration service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTGetIndexingConfigurationResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTGetIndexingConfigurationRequest
 @see AWSIoTGetIndexingConfigurationResponse
 */
- (AWSTask<AWSIoTGetIndexingConfigurationResponse *> *)getIndexingConfiguration:(AWSIoTGetIndexingConfigurationRequest *)request;

/**
 <p>Gets the indexing configuration.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetIndexingConfiguration</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetIndexingConfiguration service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTGetIndexingConfigurationRequest
 @see AWSIoTGetIndexingConfigurationResponse
 */
- (void)getIndexingConfiguration:(AWSIoTGetIndexingConfigurationRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTGetIndexingConfigurationResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets a job document.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetJobDocument</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetJobDocument service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTGetJobDocumentResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTGetJobDocumentRequest
 @see AWSIoTGetJobDocumentResponse
 */
- (AWSTask<AWSIoTGetJobDocumentResponse *> *)getJobDocument:(AWSIoTGetJobDocumentRequest *)request;

/**
 <p>Gets a job document.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetJobDocument</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetJobDocument service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTGetJobDocumentRequest
 @see AWSIoTGetJobDocumentResponse
 */
- (void)getJobDocument:(AWSIoTGetJobDocumentRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTGetJobDocumentResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets the logging options.</p><p>NOTE: use of this command is not recommended. Use <code>GetV2LoggingOptions</code> instead.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetLoggingOptions</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetLoggingOptions service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTGetLoggingOptionsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTGetLoggingOptionsRequest
 @see AWSIoTGetLoggingOptionsResponse
 */
- (AWSTask<AWSIoTGetLoggingOptionsResponse *> *)getLoggingOptions:(AWSIoTGetLoggingOptionsRequest *)request;

/**
 <p>Gets the logging options.</p><p>NOTE: use of this command is not recommended. Use <code>GetV2LoggingOptions</code> instead.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetLoggingOptions</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetLoggingOptions service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTGetLoggingOptionsRequest
 @see AWSIoTGetLoggingOptionsResponse
 */
- (void)getLoggingOptions:(AWSIoTGetLoggingOptionsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTGetLoggingOptionsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets an OTA update.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetOTAUpdate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetOTAUpdate service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTGetOTAUpdateResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTGetOTAUpdateRequest
 @see AWSIoTGetOTAUpdateResponse
 */
- (AWSTask<AWSIoTGetOTAUpdateResponse *> *)getOTAUpdate:(AWSIoTGetOTAUpdateRequest *)request;

/**
 <p>Gets an OTA update.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetOTAUpdate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetOTAUpdate service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTGetOTAUpdateRequest
 @see AWSIoTGetOTAUpdateResponse
 */
- (void)getOTAUpdate:(AWSIoTGetOTAUpdateRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTGetOTAUpdateResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Groups the aggregated values that match the query into percentile groupings. The default percentile groupings are: 1,5,25,50,75,95,99, although you can specify your own when you call <code>GetPercentiles</code>. This function returns a value for each percentile group specified (or the default percentile groupings). The percentile group "1" contains the aggregated field value that occurs in approximately one percent of the values that match the query. The percentile group "5" contains the aggregated field value that occurs in approximately five percent of the values that match the query, and so on. The result is an approximation, the more values that match the query, the more accurate the percentile values.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetPercentiles</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetPercentiles service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTGetPercentilesResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidQuery`, `AWSIoTErrorInvalidAggregation`, `AWSIoTErrorIndexNotReady`.
 
 @see AWSIoTGetPercentilesRequest
 @see AWSIoTGetPercentilesResponse
 */
- (AWSTask<AWSIoTGetPercentilesResponse *> *)getPercentiles:(AWSIoTGetPercentilesRequest *)request;

/**
 <p>Groups the aggregated values that match the query into percentile groupings. The default percentile groupings are: 1,5,25,50,75,95,99, although you can specify your own when you call <code>GetPercentiles</code>. This function returns a value for each percentile group specified (or the default percentile groupings). The percentile group "1" contains the aggregated field value that occurs in approximately one percent of the values that match the query. The percentile group "5" contains the aggregated field value that occurs in approximately five percent of the values that match the query, and so on. The result is an approximation, the more values that match the query, the more accurate the percentile values.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetPercentiles</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetPercentiles service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidQuery`, `AWSIoTErrorInvalidAggregation`, `AWSIoTErrorIndexNotReady`.
 
 @see AWSIoTGetPercentilesRequest
 @see AWSIoTGetPercentilesResponse
 */
- (void)getPercentiles:(AWSIoTGetPercentilesRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTGetPercentilesResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets information about the specified policy with the policy document of the default version.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetPolicy</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetPolicy service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTGetPolicyResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTGetPolicyRequest
 @see AWSIoTGetPolicyResponse
 */
- (AWSTask<AWSIoTGetPolicyResponse *> *)getPolicy:(AWSIoTGetPolicyRequest *)request;

/**
 <p>Gets information about the specified policy with the policy document of the default version.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetPolicy</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetPolicy service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTGetPolicyRequest
 @see AWSIoTGetPolicyResponse
 */
- (void)getPolicy:(AWSIoTGetPolicyRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTGetPolicyResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets information about the specified policy version.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetPolicyVersion</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetPolicyVersion service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTGetPolicyVersionResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTGetPolicyVersionRequest
 @see AWSIoTGetPolicyVersionResponse
 */
- (AWSTask<AWSIoTGetPolicyVersionResponse *> *)getPolicyVersion:(AWSIoTGetPolicyVersionRequest *)request;

/**
 <p>Gets information about the specified policy version.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetPolicyVersion</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetPolicyVersion service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTGetPolicyVersionRequest
 @see AWSIoTGetPolicyVersionResponse
 */
- (void)getPolicyVersion:(AWSIoTGetPolicyVersionRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTGetPolicyVersionResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets a registration code used to register a CA certificate with IoT.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetRegistrationCode</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetRegistrationCode service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTGetRegistrationCodeResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`.
 
 @see AWSIoTGetRegistrationCodeRequest
 @see AWSIoTGetRegistrationCodeResponse
 */
- (AWSTask<AWSIoTGetRegistrationCodeResponse *> *)getRegistrationCode:(AWSIoTGetRegistrationCodeRequest *)request;

/**
 <p>Gets a registration code used to register a CA certificate with IoT.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetRegistrationCode</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetRegistrationCode service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`.
 
 @see AWSIoTGetRegistrationCodeRequest
 @see AWSIoTGetRegistrationCodeResponse
 */
- (void)getRegistrationCode:(AWSIoTGetRegistrationCodeRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTGetRegistrationCodeResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Returns the count, average, sum, minimum, maximum, sum of squares, variance, and standard deviation for the specified aggregated field. If the aggregation field is of type <code>String</code>, only the count statistic is returned.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetStatistics</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetStatistics service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTGetStatisticsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidQuery`, `AWSIoTErrorInvalidAggregation`, `AWSIoTErrorIndexNotReady`.
 
 @see AWSIoTGetStatisticsRequest
 @see AWSIoTGetStatisticsResponse
 */
- (AWSTask<AWSIoTGetStatisticsResponse *> *)getStatistics:(AWSIoTGetStatisticsRequest *)request;

/**
 <p>Returns the count, average, sum, minimum, maximum, sum of squares, variance, and standard deviation for the specified aggregated field. If the aggregation field is of type <code>String</code>, only the count statistic is returned.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetStatistics</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetStatistics service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidQuery`, `AWSIoTErrorInvalidAggregation`, `AWSIoTErrorIndexNotReady`.
 
 @see AWSIoTGetStatisticsRequest
 @see AWSIoTGetStatisticsResponse
 */
- (void)getStatistics:(AWSIoTGetStatisticsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTGetStatisticsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets information about the rule.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetTopicRule</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetTopicRule service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTGetTopicRuleResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorUnauthorized`.
 
 @see AWSIoTGetTopicRuleRequest
 @see AWSIoTGetTopicRuleResponse
 */
- (AWSTask<AWSIoTGetTopicRuleResponse *> *)getTopicRule:(AWSIoTGetTopicRuleRequest *)request;

/**
 <p>Gets information about the rule.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetTopicRule</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetTopicRule service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorUnauthorized`.
 
 @see AWSIoTGetTopicRuleRequest
 @see AWSIoTGetTopicRuleResponse
 */
- (void)getTopicRule:(AWSIoTGetTopicRuleRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTGetTopicRuleResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets information about a topic rule destination.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetTopicRuleDestination</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetTopicRuleDestination service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTGetTopicRuleDestinationResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorUnauthorized`.
 
 @see AWSIoTGetTopicRuleDestinationRequest
 @see AWSIoTGetTopicRuleDestinationResponse
 */
- (AWSTask<AWSIoTGetTopicRuleDestinationResponse *> *)getTopicRuleDestination:(AWSIoTGetTopicRuleDestinationRequest *)request;

/**
 <p>Gets information about a topic rule destination.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetTopicRuleDestination</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetTopicRuleDestination service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorUnauthorized`.
 
 @see AWSIoTGetTopicRuleDestinationRequest
 @see AWSIoTGetTopicRuleDestinationResponse
 */
- (void)getTopicRuleDestination:(AWSIoTGetTopicRuleDestinationRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTGetTopicRuleDestinationResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets the fine grained logging options.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetV2LoggingOptions</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetV2LoggingOptions service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTGetV2LoggingOptionsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorNotConfigured`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTGetV2LoggingOptionsRequest
 @see AWSIoTGetV2LoggingOptionsResponse
 */
- (AWSTask<AWSIoTGetV2LoggingOptionsResponse *> *)getV2LoggingOptions:(AWSIoTGetV2LoggingOptionsRequest *)request;

/**
 <p>Gets the fine grained logging options.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">GetV2LoggingOptions</a> action.</p>
 
 @param request A container for the necessary parameters to execute the GetV2LoggingOptions service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorNotConfigured`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTGetV2LoggingOptionsRequest
 @see AWSIoTGetV2LoggingOptionsResponse
 */
- (void)getV2LoggingOptions:(AWSIoTGetV2LoggingOptionsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTGetV2LoggingOptionsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the active violations for a given Device Defender security profile.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListActiveViolations</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListActiveViolations service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListActiveViolationsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListActiveViolationsRequest
 @see AWSIoTListActiveViolationsResponse
 */
- (AWSTask<AWSIoTListActiveViolationsResponse *> *)listActiveViolations:(AWSIoTListActiveViolationsRequest *)request;

/**
 <p>Lists the active violations for a given Device Defender security profile.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListActiveViolations</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListActiveViolations service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListActiveViolationsRequest
 @see AWSIoTListActiveViolationsResponse
 */
- (void)listActiveViolations:(AWSIoTListActiveViolationsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListActiveViolationsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the policies attached to the specified thing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListAttachedPolicies</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListAttachedPolicies service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListAttachedPoliciesResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTListAttachedPoliciesRequest
 @see AWSIoTListAttachedPoliciesResponse
 */
- (AWSTask<AWSIoTListAttachedPoliciesResponse *> *)listAttachedPolicies:(AWSIoTListAttachedPoliciesRequest *)request;

/**
 <p>Lists the policies attached to the specified thing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListAttachedPolicies</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListAttachedPolicies service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTListAttachedPoliciesRequest
 @see AWSIoTListAttachedPoliciesResponse
 */
- (void)listAttachedPolicies:(AWSIoTListAttachedPoliciesRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListAttachedPoliciesResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the findings (results) of a Device Defender audit or of the audits performed during a specified time period. (Findings are retained for 90 days.)</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListAuditFindings</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListAuditFindings service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListAuditFindingsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListAuditFindingsRequest
 @see AWSIoTListAuditFindingsResponse
 */
- (AWSTask<AWSIoTListAuditFindingsResponse *> *)listAuditFindings:(AWSIoTListAuditFindingsRequest *)request;

/**
 <p>Lists the findings (results) of a Device Defender audit or of the audits performed during a specified time period. (Findings are retained for 90 days.)</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListAuditFindings</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListAuditFindings service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListAuditFindingsRequest
 @see AWSIoTListAuditFindingsResponse
 */
- (void)listAuditFindings:(AWSIoTListAuditFindingsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListAuditFindingsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets the status of audit mitigation action tasks that were executed.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListAuditMitigationActionsExecutions</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListAuditMitigationActionsExecutions service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListAuditMitigationActionsExecutionsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListAuditMitigationActionsExecutionsRequest
 @see AWSIoTListAuditMitigationActionsExecutionsResponse
 */
- (AWSTask<AWSIoTListAuditMitigationActionsExecutionsResponse *> *)listAuditMitigationActionsExecutions:(AWSIoTListAuditMitigationActionsExecutionsRequest *)request;

/**
 <p>Gets the status of audit mitigation action tasks that were executed.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListAuditMitigationActionsExecutions</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListAuditMitigationActionsExecutions service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListAuditMitigationActionsExecutionsRequest
 @see AWSIoTListAuditMitigationActionsExecutionsResponse
 */
- (void)listAuditMitigationActionsExecutions:(AWSIoTListAuditMitigationActionsExecutionsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListAuditMitigationActionsExecutionsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets a list of audit mitigation action tasks that match the specified filters.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListAuditMitigationActionsTasks</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListAuditMitigationActionsTasks service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListAuditMitigationActionsTasksResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListAuditMitigationActionsTasksRequest
 @see AWSIoTListAuditMitigationActionsTasksResponse
 */
- (AWSTask<AWSIoTListAuditMitigationActionsTasksResponse *> *)listAuditMitigationActionsTasks:(AWSIoTListAuditMitigationActionsTasksRequest *)request;

/**
 <p>Gets a list of audit mitigation action tasks that match the specified filters.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListAuditMitigationActionsTasks</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListAuditMitigationActionsTasks service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListAuditMitigationActionsTasksRequest
 @see AWSIoTListAuditMitigationActionsTasksResponse
 */
- (void)listAuditMitigationActionsTasks:(AWSIoTListAuditMitigationActionsTasksRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListAuditMitigationActionsTasksResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p> Lists your Device Defender audit listings. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListAuditSuppressions</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListAuditSuppressions service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListAuditSuppressionsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListAuditSuppressionsRequest
 @see AWSIoTListAuditSuppressionsResponse
 */
- (AWSTask<AWSIoTListAuditSuppressionsResponse *> *)listAuditSuppressions:(AWSIoTListAuditSuppressionsRequest *)request;

/**
 <p> Lists your Device Defender audit listings. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListAuditSuppressions</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListAuditSuppressions service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListAuditSuppressionsRequest
 @see AWSIoTListAuditSuppressionsResponse
 */
- (void)listAuditSuppressions:(AWSIoTListAuditSuppressionsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListAuditSuppressionsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the Device Defender audits that have been performed during a given time period.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListAuditTasks</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListAuditTasks service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListAuditTasksResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListAuditTasksRequest
 @see AWSIoTListAuditTasksResponse
 */
- (AWSTask<AWSIoTListAuditTasksResponse *> *)listAuditTasks:(AWSIoTListAuditTasksRequest *)request;

/**
 <p>Lists the Device Defender audits that have been performed during a given time period.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListAuditTasks</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListAuditTasks service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListAuditTasksRequest
 @see AWSIoTListAuditTasksResponse
 */
- (void)listAuditTasks:(AWSIoTListAuditTasksRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListAuditTasksResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the authorizers registered in your account.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListAuthorizers</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListAuthorizers service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListAuthorizersResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListAuthorizersRequest
 @see AWSIoTListAuthorizersResponse
 */
- (AWSTask<AWSIoTListAuthorizersResponse *> *)listAuthorizers:(AWSIoTListAuthorizersRequest *)request;

/**
 <p>Lists the authorizers registered in your account.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListAuthorizers</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListAuthorizers service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListAuthorizersRequest
 @see AWSIoTListAuthorizersResponse
 */
- (void)listAuthorizers:(AWSIoTListAuthorizersRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListAuthorizersResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the billing groups you have created.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListBillingGroups</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListBillingGroups service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListBillingGroupsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTListBillingGroupsRequest
 @see AWSIoTListBillingGroupsResponse
 */
- (AWSTask<AWSIoTListBillingGroupsResponse *> *)listBillingGroups:(AWSIoTListBillingGroupsRequest *)request;

/**
 <p>Lists the billing groups you have created.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListBillingGroups</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListBillingGroups service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTListBillingGroupsRequest
 @see AWSIoTListBillingGroupsResponse
 */
- (void)listBillingGroups:(AWSIoTListBillingGroupsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListBillingGroupsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the CA certificates registered for your Amazon Web Services account.</p><p>The results are paginated with a default page size of 25. You can use the returned marker to retrieve additional results.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListCACertificates</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListCACertificates service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListCACertificatesResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListCACertificatesRequest
 @see AWSIoTListCACertificatesResponse
 */
- (AWSTask<AWSIoTListCACertificatesResponse *> *)listCACertificates:(AWSIoTListCACertificatesRequest *)request;

/**
 <p>Lists the CA certificates registered for your Amazon Web Services account.</p><p>The results are paginated with a default page size of 25. You can use the returned marker to retrieve additional results.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListCACertificates</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListCACertificates service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListCACertificatesRequest
 @see AWSIoTListCACertificatesResponse
 */
- (void)listCACertificates:(AWSIoTListCACertificatesRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListCACertificatesResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the certificates registered in your Amazon Web Services account.</p><p>The results are paginated with a default page size of 25. You can use the returned marker to retrieve additional results.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListCertificates</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListCertificates service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListCertificatesResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListCertificatesRequest
 @see AWSIoTListCertificatesResponse
 */
- (AWSTask<AWSIoTListCertificatesResponse *> *)listCertificates:(AWSIoTListCertificatesRequest *)request;

/**
 <p>Lists the certificates registered in your Amazon Web Services account.</p><p>The results are paginated with a default page size of 25. You can use the returned marker to retrieve additional results.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListCertificates</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListCertificates service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListCertificatesRequest
 @see AWSIoTListCertificatesResponse
 */
- (void)listCertificates:(AWSIoTListCertificatesRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListCertificatesResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>List the device certificates signed by the specified CA certificate.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListCertificatesByCA</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListCertificatesByCA service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListCertificatesByCAResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListCertificatesByCARequest
 @see AWSIoTListCertificatesByCAResponse
 */
- (AWSTask<AWSIoTListCertificatesByCAResponse *> *)listCertificatesByCA:(AWSIoTListCertificatesByCARequest *)request;

/**
 <p>List the device certificates signed by the specified CA certificate.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListCertificatesByCA</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListCertificatesByCA service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListCertificatesByCARequest
 @see AWSIoTListCertificatesByCAResponse
 */
- (void)listCertificatesByCA:(AWSIoTListCertificatesByCARequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListCertificatesByCAResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p> Lists your Device Defender detect custom metrics. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListCustomMetrics</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListCustomMetrics service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListCustomMetricsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListCustomMetricsRequest
 @see AWSIoTListCustomMetricsResponse
 */
- (AWSTask<AWSIoTListCustomMetricsResponse *> *)listCustomMetrics:(AWSIoTListCustomMetricsRequest *)request;

/**
 <p> Lists your Device Defender detect custom metrics. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListCustomMetrics</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListCustomMetrics service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListCustomMetricsRequest
 @see AWSIoTListCustomMetricsResponse
 */
- (void)listCustomMetrics:(AWSIoTListCustomMetricsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListCustomMetricsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p> Lists mitigation actions executions for a Device Defender ML Detect Security Profile. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListDetectMitigationActionsExecutions</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListDetectMitigationActionsExecutions service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListDetectMitigationActionsExecutionsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListDetectMitigationActionsExecutionsRequest
 @see AWSIoTListDetectMitigationActionsExecutionsResponse
 */
- (AWSTask<AWSIoTListDetectMitigationActionsExecutionsResponse *> *)listDetectMitigationActionsExecutions:(AWSIoTListDetectMitigationActionsExecutionsRequest *)request;

/**
 <p> Lists mitigation actions executions for a Device Defender ML Detect Security Profile. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListDetectMitigationActionsExecutions</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListDetectMitigationActionsExecutions service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListDetectMitigationActionsExecutionsRequest
 @see AWSIoTListDetectMitigationActionsExecutionsResponse
 */
- (void)listDetectMitigationActionsExecutions:(AWSIoTListDetectMitigationActionsExecutionsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListDetectMitigationActionsExecutionsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p> List of Device Defender ML Detect mitigation actions tasks. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListDetectMitigationActionsTasks</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListDetectMitigationActionsTasks service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListDetectMitigationActionsTasksResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListDetectMitigationActionsTasksRequest
 @see AWSIoTListDetectMitigationActionsTasksResponse
 */
- (AWSTask<AWSIoTListDetectMitigationActionsTasksResponse *> *)listDetectMitigationActionsTasks:(AWSIoTListDetectMitigationActionsTasksRequest *)request;

/**
 <p> List of Device Defender ML Detect mitigation actions tasks. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListDetectMitigationActionsTasks</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListDetectMitigationActionsTasks service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListDetectMitigationActionsTasksRequest
 @see AWSIoTListDetectMitigationActionsTasksResponse
 */
- (void)listDetectMitigationActionsTasks:(AWSIoTListDetectMitigationActionsTasksRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListDetectMitigationActionsTasksResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>List the set of dimensions that are defined for your Amazon Web Services accounts.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListDimensions</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListDimensions service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListDimensionsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTListDimensionsRequest
 @see AWSIoTListDimensionsResponse
 */
- (AWSTask<AWSIoTListDimensionsResponse *> *)listDimensions:(AWSIoTListDimensionsRequest *)request;

/**
 <p>List the set of dimensions that are defined for your Amazon Web Services accounts.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListDimensions</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListDimensions service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTListDimensionsRequest
 @see AWSIoTListDimensionsResponse
 */
- (void)listDimensions:(AWSIoTListDimensionsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListDimensionsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets a list of domain configurations for the user. This list is sorted alphabetically by domain configuration name.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListDomainConfigurations</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListDomainConfigurations service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListDomainConfigurationsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListDomainConfigurationsRequest
 @see AWSIoTListDomainConfigurationsResponse
 */
- (AWSTask<AWSIoTListDomainConfigurationsResponse *> *)listDomainConfigurations:(AWSIoTListDomainConfigurationsRequest *)request;

/**
 <p>Gets a list of domain configurations for the user. This list is sorted alphabetically by domain configuration name.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListDomainConfigurations</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListDomainConfigurations service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListDomainConfigurationsRequest
 @see AWSIoTListDomainConfigurationsResponse
 */
- (void)listDomainConfigurations:(AWSIoTListDomainConfigurationsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListDomainConfigurationsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists all your fleet metrics. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListFleetMetrics</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListFleetMetrics service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListFleetMetricsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListFleetMetricsRequest
 @see AWSIoTListFleetMetricsResponse
 */
- (AWSTask<AWSIoTListFleetMetricsResponse *> *)listFleetMetrics:(AWSIoTListFleetMetricsRequest *)request;

/**
 <p>Lists all your fleet metrics. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListFleetMetrics</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListFleetMetrics service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListFleetMetricsRequest
 @see AWSIoTListFleetMetricsResponse
 */
- (void)listFleetMetrics:(AWSIoTListFleetMetricsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListFleetMetricsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the search indices.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListIndices</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListIndices service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListIndicesResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListIndicesRequest
 @see AWSIoTListIndicesResponse
 */
- (AWSTask<AWSIoTListIndicesResponse *> *)listIndices:(AWSIoTListIndicesRequest *)request;

/**
 <p>Lists the search indices.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListIndices</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListIndices service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListIndicesRequest
 @see AWSIoTListIndicesResponse
 */
- (void)listIndices:(AWSIoTListIndicesRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListIndicesResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the job executions for a job.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListJobExecutionsForJob</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListJobExecutionsForJob service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListJobExecutionsForJobResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTListJobExecutionsForJobRequest
 @see AWSIoTListJobExecutionsForJobResponse
 */
- (AWSTask<AWSIoTListJobExecutionsForJobResponse *> *)listJobExecutionsForJob:(AWSIoTListJobExecutionsForJobRequest *)request;

/**
 <p>Lists the job executions for a job.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListJobExecutionsForJob</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListJobExecutionsForJob service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTListJobExecutionsForJobRequest
 @see AWSIoTListJobExecutionsForJobResponse
 */
- (void)listJobExecutionsForJob:(AWSIoTListJobExecutionsForJobRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListJobExecutionsForJobResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the job executions for the specified thing.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListJobExecutionsForThing</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListJobExecutionsForThing service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListJobExecutionsForThingResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTListJobExecutionsForThingRequest
 @see AWSIoTListJobExecutionsForThingResponse
 */
- (AWSTask<AWSIoTListJobExecutionsForThingResponse *> *)listJobExecutionsForThing:(AWSIoTListJobExecutionsForThingRequest *)request;

/**
 <p>Lists the job executions for the specified thing.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListJobExecutionsForThing</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListJobExecutionsForThing service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTListJobExecutionsForThingRequest
 @see AWSIoTListJobExecutionsForThingResponse
 */
- (void)listJobExecutionsForThing:(AWSIoTListJobExecutionsForThingRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListJobExecutionsForThingResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Returns a list of job templates.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListJobTemplates</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListJobTemplates service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListJobTemplatesResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListJobTemplatesRequest
 @see AWSIoTListJobTemplatesResponse
 */
- (AWSTask<AWSIoTListJobTemplatesResponse *> *)listJobTemplates:(AWSIoTListJobTemplatesRequest *)request;

/**
 <p>Returns a list of job templates.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListJobTemplates</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListJobTemplates service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListJobTemplatesRequest
 @see AWSIoTListJobTemplatesResponse
 */
- (void)listJobTemplates:(AWSIoTListJobTemplatesRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListJobTemplatesResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists jobs.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListJobs</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListJobs service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListJobsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTListJobsRequest
 @see AWSIoTListJobsResponse
 */
- (AWSTask<AWSIoTListJobsResponse *> *)listJobs:(AWSIoTListJobsRequest *)request;

/**
 <p>Lists jobs.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListJobs</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListJobs service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTListJobsRequest
 @see AWSIoTListJobsResponse
 */
- (void)listJobs:(AWSIoTListJobsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListJobsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Returns a list of managed job templates.</p>
 
 @param request A container for the necessary parameters to execute the ListManagedJobTemplates service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListManagedJobTemplatesResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalServer`.
 
 @see AWSIoTListManagedJobTemplatesRequest
 @see AWSIoTListManagedJobTemplatesResponse
 */
- (AWSTask<AWSIoTListManagedJobTemplatesResponse *> *)listManagedJobTemplates:(AWSIoTListManagedJobTemplatesRequest *)request;

/**
 <p>Returns a list of managed job templates.</p>
 
 @param request A container for the necessary parameters to execute the ListManagedJobTemplates service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalServer`.
 
 @see AWSIoTListManagedJobTemplatesRequest
 @see AWSIoTListManagedJobTemplatesResponse
 */
- (void)listManagedJobTemplates:(AWSIoTListManagedJobTemplatesRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListManagedJobTemplatesResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the values reported for an IoT Device Defender metric (device-side metric, cloud-side metric, or custom metric) by the given thing during the specified time period.</p>
 
 @param request A container for the necessary parameters to execute the ListMetricValues service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListMetricValuesResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTListMetricValuesRequest
 @see AWSIoTListMetricValuesResponse
 */
- (AWSTask<AWSIoTListMetricValuesResponse *> *)listMetricValues:(AWSIoTListMetricValuesRequest *)request;

/**
 <p>Lists the values reported for an IoT Device Defender metric (device-side metric, cloud-side metric, or custom metric) by the given thing during the specified time period.</p>
 
 @param request A container for the necessary parameters to execute the ListMetricValues service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTListMetricValuesRequest
 @see AWSIoTListMetricValuesResponse
 */
- (void)listMetricValues:(AWSIoTListMetricValuesRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListMetricValuesResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets a list of all mitigation actions that match the specified filter criteria.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListMitigationActions</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListMitigationActions service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListMitigationActionsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListMitigationActionsRequest
 @see AWSIoTListMitigationActionsResponse
 */
- (AWSTask<AWSIoTListMitigationActionsResponse *> *)listMitigationActions:(AWSIoTListMitigationActionsRequest *)request;

/**
 <p>Gets a list of all mitigation actions that match the specified filter criteria.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListMitigationActions</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListMitigationActions service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListMitigationActionsRequest
 @see AWSIoTListMitigationActionsResponse
 */
- (void)listMitigationActions:(AWSIoTListMitigationActionsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListMitigationActionsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists OTA updates.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListOTAUpdates</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListOTAUpdates service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListOTAUpdatesResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTListOTAUpdatesRequest
 @see AWSIoTListOTAUpdatesResponse
 */
- (AWSTask<AWSIoTListOTAUpdatesResponse *> *)listOTAUpdates:(AWSIoTListOTAUpdatesRequest *)request;

/**
 <p>Lists OTA updates.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListOTAUpdates</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListOTAUpdates service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTListOTAUpdatesRequest
 @see AWSIoTListOTAUpdatesResponse
 */
- (void)listOTAUpdates:(AWSIoTListOTAUpdatesRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListOTAUpdatesResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists certificates that are being transferred but not yet accepted.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListOutgoingCertificates</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListOutgoingCertificates service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListOutgoingCertificatesResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListOutgoingCertificatesRequest
 @see AWSIoTListOutgoingCertificatesResponse
 */
- (AWSTask<AWSIoTListOutgoingCertificatesResponse *> *)listOutgoingCertificates:(AWSIoTListOutgoingCertificatesRequest *)request;

/**
 <p>Lists certificates that are being transferred but not yet accepted.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListOutgoingCertificates</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListOutgoingCertificates service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListOutgoingCertificatesRequest
 @see AWSIoTListOutgoingCertificatesResponse
 */
- (void)listOutgoingCertificates:(AWSIoTListOutgoingCertificatesRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListOutgoingCertificatesResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists your policies.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListPolicies</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListPolicies service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListPoliciesResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListPoliciesRequest
 @see AWSIoTListPoliciesResponse
 */
- (AWSTask<AWSIoTListPoliciesResponse *> *)listPolicies:(AWSIoTListPoliciesRequest *)request;

/**
 <p>Lists your policies.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListPolicies</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListPolicies service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListPoliciesRequest
 @see AWSIoTListPoliciesResponse
 */
- (void)listPolicies:(AWSIoTListPoliciesRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListPoliciesResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the principals associated with the specified policy.</p><p><b>Note:</b> This action is deprecated and works as expected for backward compatibility, but we won't add enhancements. Use <a>ListTargetsForPolicy</a> instead.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListPolicyPrincipals</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListPolicyPrincipals service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListPolicyPrincipalsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListPolicyPrincipalsRequest
 @see AWSIoTListPolicyPrincipalsResponse
 */
- (AWSTask<AWSIoTListPolicyPrincipalsResponse *> *)listPolicyPrincipals:(AWSIoTListPolicyPrincipalsRequest *)request;

/**
 <p>Lists the principals associated with the specified policy.</p><p><b>Note:</b> This action is deprecated and works as expected for backward compatibility, but we won't add enhancements. Use <a>ListTargetsForPolicy</a> instead.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListPolicyPrincipals</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListPolicyPrincipals service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListPolicyPrincipalsRequest
 @see AWSIoTListPolicyPrincipalsResponse
 */
- (void)listPolicyPrincipals:(AWSIoTListPolicyPrincipalsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListPolicyPrincipalsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the versions of the specified policy and identifies the default version.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListPolicyVersions</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListPolicyVersions service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListPolicyVersionsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListPolicyVersionsRequest
 @see AWSIoTListPolicyVersionsResponse
 */
- (AWSTask<AWSIoTListPolicyVersionsResponse *> *)listPolicyVersions:(AWSIoTListPolicyVersionsRequest *)request;

/**
 <p>Lists the versions of the specified policy and identifies the default version.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListPolicyVersions</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListPolicyVersions service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListPolicyVersionsRequest
 @see AWSIoTListPolicyVersionsResponse
 */
- (void)listPolicyVersions:(AWSIoTListPolicyVersionsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListPolicyVersionsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the policies attached to the specified principal. If you use an Cognito identity, the ID must be in <a href="https://docs.aws.amazon.com/cognitoidentity/latest/APIReference/API_GetCredentialsForIdentity.html#API_GetCredentialsForIdentity_RequestSyntax">AmazonCognito Identity format</a>.</p><p><b>Note:</b> This action is deprecated and works as expected for backward compatibility, but we won't add enhancements. Use <a>ListAttachedPolicies</a> instead.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListPrincipalPolicies</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListPrincipalPolicies service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListPrincipalPoliciesResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListPrincipalPoliciesRequest
 @see AWSIoTListPrincipalPoliciesResponse
 */
- (AWSTask<AWSIoTListPrincipalPoliciesResponse *> *)listPrincipalPolicies:(AWSIoTListPrincipalPoliciesRequest *)request;

/**
 <p>Lists the policies attached to the specified principal. If you use an Cognito identity, the ID must be in <a href="https://docs.aws.amazon.com/cognitoidentity/latest/APIReference/API_GetCredentialsForIdentity.html#API_GetCredentialsForIdentity_RequestSyntax">AmazonCognito Identity format</a>.</p><p><b>Note:</b> This action is deprecated and works as expected for backward compatibility, but we won't add enhancements. Use <a>ListAttachedPolicies</a> instead.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListPrincipalPolicies</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListPrincipalPolicies service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListPrincipalPoliciesRequest
 @see AWSIoTListPrincipalPoliciesResponse
 */
- (void)listPrincipalPolicies:(AWSIoTListPrincipalPoliciesRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListPrincipalPoliciesResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the things associated with the specified principal. A principal can be X.509 certificates, IAM users, groups, and roles, Amazon Cognito identities or federated identities. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListPrincipalThings</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListPrincipalThings service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListPrincipalThingsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTListPrincipalThingsRequest
 @see AWSIoTListPrincipalThingsResponse
 */
- (AWSTask<AWSIoTListPrincipalThingsResponse *> *)listPrincipalThings:(AWSIoTListPrincipalThingsRequest *)request;

/**
 <p>Lists the things associated with the specified principal. A principal can be X.509 certificates, IAM users, groups, and roles, Amazon Cognito identities or federated identities. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListPrincipalThings</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListPrincipalThings service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTListPrincipalThingsRequest
 @see AWSIoTListPrincipalThingsResponse
 */
- (void)listPrincipalThings:(AWSIoTListPrincipalThingsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListPrincipalThingsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>A list of provisioning template versions.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListProvisioningTemplateVersions</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListProvisioningTemplateVersions service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListProvisioningTemplateVersionsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorUnauthorized`.
 
 @see AWSIoTListProvisioningTemplateVersionsRequest
 @see AWSIoTListProvisioningTemplateVersionsResponse
 */
- (AWSTask<AWSIoTListProvisioningTemplateVersionsResponse *> *)listProvisioningTemplateVersions:(AWSIoTListProvisioningTemplateVersionsRequest *)request;

/**
 <p>A list of provisioning template versions.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListProvisioningTemplateVersions</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListProvisioningTemplateVersions service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorUnauthorized`.
 
 @see AWSIoTListProvisioningTemplateVersionsRequest
 @see AWSIoTListProvisioningTemplateVersionsResponse
 */
- (void)listProvisioningTemplateVersions:(AWSIoTListProvisioningTemplateVersionsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListProvisioningTemplateVersionsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the provisioning templates in your Amazon Web Services account.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListProvisioningTemplates</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListProvisioningTemplates service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListProvisioningTemplatesResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`.
 
 @see AWSIoTListProvisioningTemplatesRequest
 @see AWSIoTListProvisioningTemplatesResponse
 */
- (AWSTask<AWSIoTListProvisioningTemplatesResponse *> *)listProvisioningTemplates:(AWSIoTListProvisioningTemplatesRequest *)request;

/**
 <p>Lists the provisioning templates in your Amazon Web Services account.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListProvisioningTemplates</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListProvisioningTemplates service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`.
 
 @see AWSIoTListProvisioningTemplatesRequest
 @see AWSIoTListProvisioningTemplatesResponse
 */
- (void)listProvisioningTemplates:(AWSIoTListProvisioningTemplatesRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListProvisioningTemplatesResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>The related resources of an Audit finding. The following resources can be returned from calling this API:</p><ul><li><p>DEVICE_CERTIFICATE</p></li><li><p>CA_CERTIFICATE</p></li><li><p>IOT_POLICY</p></li><li><p>COGNITO_IDENTITY_POOL</p></li><li><p>CLIENT_ID</p></li><li><p>ACCOUNT_SETTINGS</p></li><li><p>ROLE_ALIAS</p></li><li><p>IAM_ROLE</p></li><li><p>ISSUER_CERTIFICATE</p></li></ul><note><p>This API is similar to DescribeAuditFinding's <a href="https://docs.aws.amazon.com/iot/latest/apireference/API_DescribeAuditFinding.html">RelatedResources</a> but provides pagination and is not limited to 10 resources. When calling <a href="https://docs.aws.amazon.com/iot/latest/apireference/API_DescribeAuditFinding.html">DescribeAuditFinding</a> for the intermediate CA revoked for active device certificates check, RelatedResources will not be populated. You must use this API, ListRelatedResourcesForAuditFinding, to list the certificates.</p></note>
 
 @param request A container for the necessary parameters to execute the ListRelatedResourcesForAuditFinding service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListRelatedResourcesForAuditFindingResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListRelatedResourcesForAuditFindingRequest
 @see AWSIoTListRelatedResourcesForAuditFindingResponse
 */
- (AWSTask<AWSIoTListRelatedResourcesForAuditFindingResponse *> *)listRelatedResourcesForAuditFinding:(AWSIoTListRelatedResourcesForAuditFindingRequest *)request;

/**
 <p>The related resources of an Audit finding. The following resources can be returned from calling this API:</p><ul><li><p>DEVICE_CERTIFICATE</p></li><li><p>CA_CERTIFICATE</p></li><li><p>IOT_POLICY</p></li><li><p>COGNITO_IDENTITY_POOL</p></li><li><p>CLIENT_ID</p></li><li><p>ACCOUNT_SETTINGS</p></li><li><p>ROLE_ALIAS</p></li><li><p>IAM_ROLE</p></li><li><p>ISSUER_CERTIFICATE</p></li></ul><note><p>This API is similar to DescribeAuditFinding's <a href="https://docs.aws.amazon.com/iot/latest/apireference/API_DescribeAuditFinding.html">RelatedResources</a> but provides pagination and is not limited to 10 resources. When calling <a href="https://docs.aws.amazon.com/iot/latest/apireference/API_DescribeAuditFinding.html">DescribeAuditFinding</a> for the intermediate CA revoked for active device certificates check, RelatedResources will not be populated. You must use this API, ListRelatedResourcesForAuditFinding, to list the certificates.</p></note>
 
 @param request A container for the necessary parameters to execute the ListRelatedResourcesForAuditFinding service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListRelatedResourcesForAuditFindingRequest
 @see AWSIoTListRelatedResourcesForAuditFindingResponse
 */
- (void)listRelatedResourcesForAuditFinding:(AWSIoTListRelatedResourcesForAuditFindingRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListRelatedResourcesForAuditFindingResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the role aliases registered in your account.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListRoleAliases</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListRoleAliases service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListRoleAliasesResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListRoleAliasesRequest
 @see AWSIoTListRoleAliasesResponse
 */
- (AWSTask<AWSIoTListRoleAliasesResponse *> *)listRoleAliases:(AWSIoTListRoleAliasesRequest *)request;

/**
 <p>Lists the role aliases registered in your account.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListRoleAliases</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListRoleAliases service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListRoleAliasesRequest
 @see AWSIoTListRoleAliasesResponse
 */
- (void)listRoleAliases:(AWSIoTListRoleAliasesRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListRoleAliasesResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists all of your scheduled audits.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListScheduledAudits</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListScheduledAudits service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListScheduledAuditsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListScheduledAuditsRequest
 @see AWSIoTListScheduledAuditsResponse
 */
- (AWSTask<AWSIoTListScheduledAuditsResponse *> *)listScheduledAudits:(AWSIoTListScheduledAuditsRequest *)request;

/**
 <p>Lists all of your scheduled audits.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListScheduledAudits</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListScheduledAudits service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListScheduledAuditsRequest
 @see AWSIoTListScheduledAuditsResponse
 */
- (void)listScheduledAudits:(AWSIoTListScheduledAuditsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListScheduledAuditsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the Device Defender security profiles you've created. You can filter security profiles by dimension or custom metric.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListSecurityProfiles</a> action.</p><note><p><code>dimensionName</code> and <code>metricName</code> cannot be used in the same request.</p></note>
 
 @param request A container for the necessary parameters to execute the ListSecurityProfiles service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListSecurityProfilesResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTListSecurityProfilesRequest
 @see AWSIoTListSecurityProfilesResponse
 */
- (AWSTask<AWSIoTListSecurityProfilesResponse *> *)listSecurityProfiles:(AWSIoTListSecurityProfilesRequest *)request;

/**
 <p>Lists the Device Defender security profiles you've created. You can filter security profiles by dimension or custom metric.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListSecurityProfiles</a> action.</p><note><p><code>dimensionName</code> and <code>metricName</code> cannot be used in the same request.</p></note>
 
 @param request A container for the necessary parameters to execute the ListSecurityProfiles service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTListSecurityProfilesRequest
 @see AWSIoTListSecurityProfilesResponse
 */
- (void)listSecurityProfiles:(AWSIoTListSecurityProfilesRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListSecurityProfilesResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the Device Defender security profiles attached to a target (thing group).</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListSecurityProfilesForTarget</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListSecurityProfilesForTarget service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListSecurityProfilesForTargetResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTListSecurityProfilesForTargetRequest
 @see AWSIoTListSecurityProfilesForTargetResponse
 */
- (AWSTask<AWSIoTListSecurityProfilesForTargetResponse *> *)listSecurityProfilesForTarget:(AWSIoTListSecurityProfilesForTargetRequest *)request;

/**
 <p>Lists the Device Defender security profiles attached to a target (thing group).</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListSecurityProfilesForTarget</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListSecurityProfilesForTarget service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTListSecurityProfilesForTargetRequest
 @see AWSIoTListSecurityProfilesForTargetResponse
 */
- (void)listSecurityProfilesForTarget:(AWSIoTListSecurityProfilesForTargetRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListSecurityProfilesForTargetResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists all of the streams in your Amazon Web Services account.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListStreams</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListStreams service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListStreamsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListStreamsRequest
 @see AWSIoTListStreamsResponse
 */
- (AWSTask<AWSIoTListStreamsResponse *> *)listStreams:(AWSIoTListStreamsRequest *)request;

/**
 <p>Lists all of the streams in your Amazon Web Services account.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListStreams</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListStreams service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListStreamsRequest
 @see AWSIoTListStreamsResponse
 */
- (void)listStreams:(AWSIoTListStreamsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListStreamsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the tags (metadata) you have assigned to the resource.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListTagsForResource</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListTagsForResource service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListTagsForResourceResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTListTagsForResourceRequest
 @see AWSIoTListTagsForResourceResponse
 */
- (AWSTask<AWSIoTListTagsForResourceResponse *> *)listTagsForResource:(AWSIoTListTagsForResourceRequest *)request;

/**
 <p>Lists the tags (metadata) you have assigned to the resource.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListTagsForResource</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListTagsForResource service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTListTagsForResourceRequest
 @see AWSIoTListTagsForResourceResponse
 */
- (void)listTagsForResource:(AWSIoTListTagsForResourceRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListTagsForResourceResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>List targets for the specified policy.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListTargetsForPolicy</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListTargetsForPolicy service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListTargetsForPolicyResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTListTargetsForPolicyRequest
 @see AWSIoTListTargetsForPolicyResponse
 */
- (AWSTask<AWSIoTListTargetsForPolicyResponse *> *)listTargetsForPolicy:(AWSIoTListTargetsForPolicyRequest *)request;

/**
 <p>List targets for the specified policy.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListTargetsForPolicy</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListTargetsForPolicy service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTListTargetsForPolicyRequest
 @see AWSIoTListTargetsForPolicyResponse
 */
- (void)listTargetsForPolicy:(AWSIoTListTargetsForPolicyRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListTargetsForPolicyResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the targets (thing groups) associated with a given Device Defender security profile.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListTargetsForSecurityProfile</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListTargetsForSecurityProfile service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListTargetsForSecurityProfileResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListTargetsForSecurityProfileRequest
 @see AWSIoTListTargetsForSecurityProfileResponse
 */
- (AWSTask<AWSIoTListTargetsForSecurityProfileResponse *> *)listTargetsForSecurityProfile:(AWSIoTListTargetsForSecurityProfileRequest *)request;

/**
 <p>Lists the targets (thing groups) associated with a given Device Defender security profile.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListTargetsForSecurityProfile</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListTargetsForSecurityProfile service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListTargetsForSecurityProfileRequest
 @see AWSIoTListTargetsForSecurityProfileResponse
 */
- (void)listTargetsForSecurityProfile:(AWSIoTListTargetsForSecurityProfileRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListTargetsForSecurityProfileResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>List the thing groups in your account.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListThingGroups</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListThingGroups service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListThingGroupsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTListThingGroupsRequest
 @see AWSIoTListThingGroupsResponse
 */
- (AWSTask<AWSIoTListThingGroupsResponse *> *)listThingGroups:(AWSIoTListThingGroupsRequest *)request;

/**
 <p>List the thing groups in your account.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListThingGroups</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListThingGroups service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTListThingGroupsRequest
 @see AWSIoTListThingGroupsResponse
 */
- (void)listThingGroups:(AWSIoTListThingGroupsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListThingGroupsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>List the thing groups to which the specified thing belongs.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListThingGroupsForThing</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListThingGroupsForThing service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListThingGroupsForThingResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTListThingGroupsForThingRequest
 @see AWSIoTListThingGroupsForThingResponse
 */
- (AWSTask<AWSIoTListThingGroupsForThingResponse *> *)listThingGroupsForThing:(AWSIoTListThingGroupsForThingRequest *)request;

/**
 <p>List the thing groups to which the specified thing belongs.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListThingGroupsForThing</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListThingGroupsForThing service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTListThingGroupsForThingRequest
 @see AWSIoTListThingGroupsForThingResponse
 */
- (void)listThingGroupsForThing:(AWSIoTListThingGroupsForThingRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListThingGroupsForThingResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the principals associated with the specified thing. A principal can be X.509 certificates, IAM users, groups, and roles, Amazon Cognito identities or federated identities.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListThingPrincipals</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListThingPrincipals service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListThingPrincipalsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTListThingPrincipalsRequest
 @see AWSIoTListThingPrincipalsResponse
 */
- (AWSTask<AWSIoTListThingPrincipalsResponse *> *)listThingPrincipals:(AWSIoTListThingPrincipalsRequest *)request;

/**
 <p>Lists the principals associated with the specified thing. A principal can be X.509 certificates, IAM users, groups, and roles, Amazon Cognito identities or federated identities.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListThingPrincipals</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListThingPrincipals service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTListThingPrincipalsRequest
 @see AWSIoTListThingPrincipalsResponse
 */
- (void)listThingPrincipals:(AWSIoTListThingPrincipalsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListThingPrincipalsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Information about the thing registration tasks.</p>
 
 @param request A container for the necessary parameters to execute the ListThingRegistrationTaskReports service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListThingRegistrationTaskReportsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListThingRegistrationTaskReportsRequest
 @see AWSIoTListThingRegistrationTaskReportsResponse
 */
- (AWSTask<AWSIoTListThingRegistrationTaskReportsResponse *> *)listThingRegistrationTaskReports:(AWSIoTListThingRegistrationTaskReportsRequest *)request;

/**
 <p>Information about the thing registration tasks.</p>
 
 @param request A container for the necessary parameters to execute the ListThingRegistrationTaskReports service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListThingRegistrationTaskReportsRequest
 @see AWSIoTListThingRegistrationTaskReportsResponse
 */
- (void)listThingRegistrationTaskReports:(AWSIoTListThingRegistrationTaskReportsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListThingRegistrationTaskReportsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>List bulk thing provisioning tasks.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListThingRegistrationTasks</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListThingRegistrationTasks service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListThingRegistrationTasksResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListThingRegistrationTasksRequest
 @see AWSIoTListThingRegistrationTasksResponse
 */
- (AWSTask<AWSIoTListThingRegistrationTasksResponse *> *)listThingRegistrationTasks:(AWSIoTListThingRegistrationTasksRequest *)request;

/**
 <p>List bulk thing provisioning tasks.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListThingRegistrationTasks</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListThingRegistrationTasks service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListThingRegistrationTasksRequest
 @see AWSIoTListThingRegistrationTasksResponse
 */
- (void)listThingRegistrationTasks:(AWSIoTListThingRegistrationTasksRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListThingRegistrationTasksResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the existing thing types.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListThingTypes</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListThingTypes service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListThingTypesResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListThingTypesRequest
 @see AWSIoTListThingTypesResponse
 */
- (AWSTask<AWSIoTListThingTypesResponse *> *)listThingTypes:(AWSIoTListThingTypesRequest *)request;

/**
 <p>Lists the existing thing types.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListThingTypes</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListThingTypes service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListThingTypesRequest
 @see AWSIoTListThingTypesResponse
 */
- (void)listThingTypes:(AWSIoTListThingTypesRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListThingTypesResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists your things. Use the <b>attributeName</b> and <b>attributeValue</b> parameters to filter your things. For example, calling <code>ListThings</code> with attributeName=Color and attributeValue=Red retrieves all things in the registry that contain an attribute <b>Color</b> with the value <b>Red</b>. For more information, see <a href="https://docs.aws.amazon.com/iot/latest/developerguide/thing-registry.html#list-things">List Things</a> from the <i>Amazon Web Services IoT Core Developer Guide</i>.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListThings</a> action.</p><note><p>You will not be charged for calling this API if an <code>Access denied</code> error is returned. You will also not be charged if no attributes or pagination token was provided in request and no pagination token and no results were returned.</p></note>
 
 @param request A container for the necessary parameters to execute the ListThings service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListThingsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListThingsRequest
 @see AWSIoTListThingsResponse
 */
- (AWSTask<AWSIoTListThingsResponse *> *)listThings:(AWSIoTListThingsRequest *)request;

/**
 <p>Lists your things. Use the <b>attributeName</b> and <b>attributeValue</b> parameters to filter your things. For example, calling <code>ListThings</code> with attributeName=Color and attributeValue=Red retrieves all things in the registry that contain an attribute <b>Color</b> with the value <b>Red</b>. For more information, see <a href="https://docs.aws.amazon.com/iot/latest/developerguide/thing-registry.html#list-things">List Things</a> from the <i>Amazon Web Services IoT Core Developer Guide</i>.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListThings</a> action.</p><note><p>You will not be charged for calling this API if an <code>Access denied</code> error is returned. You will also not be charged if no attributes or pagination token was provided in request and no pagination token and no results were returned.</p></note>
 
 @param request A container for the necessary parameters to execute the ListThings service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListThingsRequest
 @see AWSIoTListThingsResponse
 */
- (void)listThings:(AWSIoTListThingsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListThingsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the things you have added to the given billing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListThingsInBillingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListThingsInBillingGroup service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListThingsInBillingGroupResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTListThingsInBillingGroupRequest
 @see AWSIoTListThingsInBillingGroupResponse
 */
- (AWSTask<AWSIoTListThingsInBillingGroupResponse *> *)listThingsInBillingGroup:(AWSIoTListThingsInBillingGroupRequest *)request;

/**
 <p>Lists the things you have added to the given billing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListThingsInBillingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListThingsInBillingGroup service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTListThingsInBillingGroupRequest
 @see AWSIoTListThingsInBillingGroupResponse
 */
- (void)listThingsInBillingGroup:(AWSIoTListThingsInBillingGroupRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListThingsInBillingGroupResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the things in the specified group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListThingsInThingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListThingsInThingGroup service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListThingsInThingGroupResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTListThingsInThingGroupRequest
 @see AWSIoTListThingsInThingGroupResponse
 */
- (AWSTask<AWSIoTListThingsInThingGroupResponse *> *)listThingsInThingGroup:(AWSIoTListThingsInThingGroupRequest *)request;

/**
 <p>Lists the things in the specified group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListThingsInThingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListThingsInThingGroup service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTListThingsInThingGroupRequest
 @see AWSIoTListThingsInThingGroupResponse
 */
- (void)listThingsInThingGroup:(AWSIoTListThingsInThingGroupRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListThingsInThingGroupResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists all the topic rule destinations in your Amazon Web Services account.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListTopicRuleDestinations</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListTopicRuleDestinations service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListTopicRuleDestinationsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorUnauthorized`.
 
 @see AWSIoTListTopicRuleDestinationsRequest
 @see AWSIoTListTopicRuleDestinationsResponse
 */
- (AWSTask<AWSIoTListTopicRuleDestinationsResponse *> *)listTopicRuleDestinations:(AWSIoTListTopicRuleDestinationsRequest *)request;

/**
 <p>Lists all the topic rule destinations in your Amazon Web Services account.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListTopicRuleDestinations</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListTopicRuleDestinations service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorUnauthorized`.
 
 @see AWSIoTListTopicRuleDestinationsRequest
 @see AWSIoTListTopicRuleDestinationsResponse
 */
- (void)listTopicRuleDestinations:(AWSIoTListTopicRuleDestinationsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListTopicRuleDestinationsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the rules for the specific topic.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListTopicRules</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListTopicRules service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListTopicRulesResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTListTopicRulesRequest
 @see AWSIoTListTopicRulesResponse
 */
- (AWSTask<AWSIoTListTopicRulesResponse *> *)listTopicRules:(AWSIoTListTopicRulesRequest *)request;

/**
 <p>Lists the rules for the specific topic.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListTopicRules</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListTopicRules service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTListTopicRulesRequest
 @see AWSIoTListTopicRulesResponse
 */
- (void)listTopicRules:(AWSIoTListTopicRulesRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListTopicRulesResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists logging levels.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListV2LoggingLevels</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListV2LoggingLevels service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListV2LoggingLevelsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorNotConfigured`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTListV2LoggingLevelsRequest
 @see AWSIoTListV2LoggingLevelsResponse
 */
- (AWSTask<AWSIoTListV2LoggingLevelsResponse *> *)listV2LoggingLevels:(AWSIoTListV2LoggingLevelsRequest *)request;

/**
 <p>Lists logging levels.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListV2LoggingLevels</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListV2LoggingLevels service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorNotConfigured`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTListV2LoggingLevelsRequest
 @see AWSIoTListV2LoggingLevelsResponse
 */
- (void)listV2LoggingLevels:(AWSIoTListV2LoggingLevelsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListV2LoggingLevelsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the Device Defender security profile violations discovered during the given time period. You can use filters to limit the results to those alerts issued for a particular security profile, behavior, or thing (device).</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListViolationEvents</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListViolationEvents service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTListViolationEventsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListViolationEventsRequest
 @see AWSIoTListViolationEventsResponse
 */
- (AWSTask<AWSIoTListViolationEventsResponse *> *)listViolationEvents:(AWSIoTListViolationEventsRequest *)request;

/**
 <p>Lists the Device Defender security profile violations discovered during the given time period. You can use filters to limit the results to those alerts issued for a particular security profile, behavior, or thing (device).</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ListViolationEvents</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ListViolationEvents service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTListViolationEventsRequest
 @see AWSIoTListViolationEventsResponse
 */
- (void)listViolationEvents:(AWSIoTListViolationEventsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTListViolationEventsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Set a verification state and provide a description of that verification state on a violation (detect alarm).</p>
 
 @param request A container for the necessary parameters to execute the PutVerificationStateOnViolation service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTPutVerificationStateOnViolationResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTPutVerificationStateOnViolationRequest
 @see AWSIoTPutVerificationStateOnViolationResponse
 */
- (AWSTask<AWSIoTPutVerificationStateOnViolationResponse *> *)putVerificationStateOnViolation:(AWSIoTPutVerificationStateOnViolationRequest *)request;

/**
 <p>Set a verification state and provide a description of that verification state on a violation (detect alarm).</p>
 
 @param request A container for the necessary parameters to execute the PutVerificationStateOnViolation service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTPutVerificationStateOnViolationRequest
 @see AWSIoTPutVerificationStateOnViolationResponse
 */
- (void)putVerificationStateOnViolation:(AWSIoTPutVerificationStateOnViolationRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTPutVerificationStateOnViolationResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Registers a CA certificate with Amazon Web Services IoT Core. There is no limit to the number of CA certificates you can register in your Amazon Web Services account. You can register up to 10 CA certificates with the same <code>CA subject field</code> per Amazon Web Services account.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">RegisterCACertificate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the RegisterCACertificate service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTRegisterCACertificateResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorRegistrationCodeValidation`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorCertificateValidation`, `AWSIoTErrorThrottling`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTRegisterCACertificateRequest
 @see AWSIoTRegisterCACertificateResponse
 */
- (AWSTask<AWSIoTRegisterCACertificateResponse *> *)registerCACertificate:(AWSIoTRegisterCACertificateRequest *)request;

/**
 <p>Registers a CA certificate with Amazon Web Services IoT Core. There is no limit to the number of CA certificates you can register in your Amazon Web Services account. You can register up to 10 CA certificates with the same <code>CA subject field</code> per Amazon Web Services account.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">RegisterCACertificate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the RegisterCACertificate service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorRegistrationCodeValidation`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorCertificateValidation`, `AWSIoTErrorThrottling`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTRegisterCACertificateRequest
 @see AWSIoTRegisterCACertificateResponse
 */
- (void)registerCACertificate:(AWSIoTRegisterCACertificateRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTRegisterCACertificateResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Registers a device certificate with IoT in the same <a href="https://docs.aws.amazon.com/iot/latest/apireference/API_CertificateDescription.html#iot-Type-CertificateDescription-certificateMode">certificate mode</a> as the signing CA. If you have more than one CA certificate that has the same subject field, you must specify the CA certificate that was used to sign the device certificate being registered.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">RegisterCertificate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the RegisterCertificate service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTRegisterCertificateResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorCertificateValidation`, `AWSIoTErrorCertificateState`, `AWSIoTErrorCertificateConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTRegisterCertificateRequest
 @see AWSIoTRegisterCertificateResponse
 */
- (AWSTask<AWSIoTRegisterCertificateResponse *> *)registerCertificate:(AWSIoTRegisterCertificateRequest *)request;

/**
 <p>Registers a device certificate with IoT in the same <a href="https://docs.aws.amazon.com/iot/latest/apireference/API_CertificateDescription.html#iot-Type-CertificateDescription-certificateMode">certificate mode</a> as the signing CA. If you have more than one CA certificate that has the same subject field, you must specify the CA certificate that was used to sign the device certificate being registered.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">RegisterCertificate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the RegisterCertificate service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorCertificateValidation`, `AWSIoTErrorCertificateState`, `AWSIoTErrorCertificateConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTRegisterCertificateRequest
 @see AWSIoTRegisterCertificateResponse
 */
- (void)registerCertificate:(AWSIoTRegisterCertificateRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTRegisterCertificateResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Register a certificate that does not have a certificate authority (CA). For supported certificates, consult <a href="https://docs.aws.amazon.com/iot/latest/developerguide/x509-client-certs.html#x509-cert-algorithms"> Certificate signing algorithms supported by IoT</a>. </p>
 
 @param request A container for the necessary parameters to execute the RegisterCertificateWithoutCA service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTRegisterCertificateWithoutCAResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorCertificateState`, `AWSIoTErrorCertificateValidation`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTRegisterCertificateWithoutCARequest
 @see AWSIoTRegisterCertificateWithoutCAResponse
 */
- (AWSTask<AWSIoTRegisterCertificateWithoutCAResponse *> *)registerCertificateWithoutCA:(AWSIoTRegisterCertificateWithoutCARequest *)request;

/**
 <p>Register a certificate that does not have a certificate authority (CA). For supported certificates, consult <a href="https://docs.aws.amazon.com/iot/latest/developerguide/x509-client-certs.html#x509-cert-algorithms"> Certificate signing algorithms supported by IoT</a>. </p>
 
 @param request A container for the necessary parameters to execute the RegisterCertificateWithoutCA service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceAlreadyExists`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorCertificateState`, `AWSIoTErrorCertificateValidation`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTRegisterCertificateWithoutCARequest
 @see AWSIoTRegisterCertificateWithoutCAResponse
 */
- (void)registerCertificateWithoutCA:(AWSIoTRegisterCertificateWithoutCARequest *)request completionHandler:(void (^ _Nullable)(AWSIoTRegisterCertificateWithoutCAResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Provisions a thing in the device registry. RegisterThing calls other IoT control plane APIs. These calls might exceed your account level <a href="https://docs.aws.amazon.com/general/latest/gr/aws_service_limits.html#limits_iot"> IoT Throttling Limits</a> and cause throttle errors. Please contact <a href="https://console.aws.amazon.com/support/home">Amazon Web Services Customer Support</a> to raise your throttling limits if necessary.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">RegisterThing</a> action.</p>
 
 @param request A container for the necessary parameters to execute the RegisterThing service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTRegisterThingResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorThrottling`, `AWSIoTErrorConflictingResourceUpdate`, `AWSIoTErrorResourceRegistrationFailure`.
 
 @see AWSIoTRegisterThingRequest
 @see AWSIoTRegisterThingResponse
 */
- (AWSTask<AWSIoTRegisterThingResponse *> *)registerThing:(AWSIoTRegisterThingRequest *)request;

/**
 <p>Provisions a thing in the device registry. RegisterThing calls other IoT control plane APIs. These calls might exceed your account level <a href="https://docs.aws.amazon.com/general/latest/gr/aws_service_limits.html#limits_iot"> IoT Throttling Limits</a> and cause throttle errors. Please contact <a href="https://console.aws.amazon.com/support/home">Amazon Web Services Customer Support</a> to raise your throttling limits if necessary.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">RegisterThing</a> action.</p>
 
 @param request A container for the necessary parameters to execute the RegisterThing service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorThrottling`, `AWSIoTErrorConflictingResourceUpdate`, `AWSIoTErrorResourceRegistrationFailure`.
 
 @see AWSIoTRegisterThingRequest
 @see AWSIoTRegisterThingResponse
 */
- (void)registerThing:(AWSIoTRegisterThingRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTRegisterThingResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Rejects a pending certificate transfer. After IoT rejects a certificate transfer, the certificate status changes from <b>PENDING_TRANSFER</b> to <b>INACTIVE</b>.</p><p>To check for pending certificate transfers, call <a>ListCertificates</a> to enumerate your certificates.</p><p>This operation can only be called by the transfer destination. After it is called, the certificate will be returned to the source's account in the INACTIVE state.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">RejectCertificateTransfer</a> action.</p>
 
 @param request A container for the necessary parameters to execute the RejectCertificateTransfer service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorTransferAlreadyCompleted`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTRejectCertificateTransferRequest
 */
- (AWSTask *)rejectCertificateTransfer:(AWSIoTRejectCertificateTransferRequest *)request;

/**
 <p>Rejects a pending certificate transfer. After IoT rejects a certificate transfer, the certificate status changes from <b>PENDING_TRANSFER</b> to <b>INACTIVE</b>.</p><p>To check for pending certificate transfers, call <a>ListCertificates</a> to enumerate your certificates.</p><p>This operation can only be called by the transfer destination. After it is called, the certificate will be returned to the source's account in the INACTIVE state.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">RejectCertificateTransfer</a> action.</p>
 
 @param request A container for the necessary parameters to execute the RejectCertificateTransfer service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorTransferAlreadyCompleted`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTRejectCertificateTransferRequest
 */
- (void)rejectCertificateTransfer:(AWSIoTRejectCertificateTransferRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Removes the given thing from the billing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">RemoveThingFromBillingGroup</a> action.</p><note><p>This call is asynchronous. It might take several seconds for the detachment to propagate.</p></note>
 
 @param request A container for the necessary parameters to execute the RemoveThingFromBillingGroup service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTRemoveThingFromBillingGroupResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTRemoveThingFromBillingGroupRequest
 @see AWSIoTRemoveThingFromBillingGroupResponse
 */
- (AWSTask<AWSIoTRemoveThingFromBillingGroupResponse *> *)removeThingFromBillingGroup:(AWSIoTRemoveThingFromBillingGroupRequest *)request;

/**
 <p>Removes the given thing from the billing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">RemoveThingFromBillingGroup</a> action.</p><note><p>This call is asynchronous. It might take several seconds for the detachment to propagate.</p></note>
 
 @param request A container for the necessary parameters to execute the RemoveThingFromBillingGroup service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTRemoveThingFromBillingGroupRequest
 @see AWSIoTRemoveThingFromBillingGroupResponse
 */
- (void)removeThingFromBillingGroup:(AWSIoTRemoveThingFromBillingGroupRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTRemoveThingFromBillingGroupResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Remove the specified thing from the specified group.</p><p>You must specify either a <code>thingGroupArn</code> or a <code>thingGroupName</code> to identify the thing group and either a <code>thingArn</code> or a <code>thingName</code> to identify the thing to remove from the thing group. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">RemoveThingFromThingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the RemoveThingFromThingGroup service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTRemoveThingFromThingGroupResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTRemoveThingFromThingGroupRequest
 @see AWSIoTRemoveThingFromThingGroupResponse
 */
- (AWSTask<AWSIoTRemoveThingFromThingGroupResponse *> *)removeThingFromThingGroup:(AWSIoTRemoveThingFromThingGroupRequest *)request;

/**
 <p>Remove the specified thing from the specified group.</p><p>You must specify either a <code>thingGroupArn</code> or a <code>thingGroupName</code> to identify the thing group and either a <code>thingArn</code> or a <code>thingName</code> to identify the thing to remove from the thing group. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">RemoveThingFromThingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the RemoveThingFromThingGroup service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTRemoveThingFromThingGroupRequest
 @see AWSIoTRemoveThingFromThingGroupResponse
 */
- (void)removeThingFromThingGroup:(AWSIoTRemoveThingFromThingGroupRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTRemoveThingFromThingGroupResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Replaces the rule. You must specify all parameters for the new rule. Creating rules is an administrator-level action. Any user who has permission to create rules will be able to access data processed by the rule.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ReplaceTopicRule</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ReplaceTopicRule service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorSqlParse`, `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorConflictingResourceUpdate`.
 
 @see AWSIoTReplaceTopicRuleRequest
 */
- (AWSTask *)replaceTopicRule:(AWSIoTReplaceTopicRuleRequest *)request;

/**
 <p>Replaces the rule. You must specify all parameters for the new rule. Creating rules is an administrator-level action. Any user who has permission to create rules will be able to access data processed by the rule.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ReplaceTopicRule</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ReplaceTopicRule service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorSqlParse`, `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorConflictingResourceUpdate`.
 
 @see AWSIoTReplaceTopicRuleRequest
 */
- (void)replaceTopicRule:(AWSIoTReplaceTopicRuleRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>The query search index.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">SearchIndex</a> action.</p>
 
 @param request A container for the necessary parameters to execute the SearchIndex service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTSearchIndexResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidQuery`, `AWSIoTErrorIndexNotReady`.
 
 @see AWSIoTSearchIndexRequest
 @see AWSIoTSearchIndexResponse
 */
- (AWSTask<AWSIoTSearchIndexResponse *> *)searchIndex:(AWSIoTSearchIndexRequest *)request;

/**
 <p>The query search index.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">SearchIndex</a> action.</p>
 
 @param request A container for the necessary parameters to execute the SearchIndex service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidQuery`, `AWSIoTErrorIndexNotReady`.
 
 @see AWSIoTSearchIndexRequest
 @see AWSIoTSearchIndexResponse
 */
- (void)searchIndex:(AWSIoTSearchIndexRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTSearchIndexResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Sets the default authorizer. This will be used if a websocket connection is made without specifying an authorizer.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">SetDefaultAuthorizer</a> action.</p>
 
 @param request A container for the necessary parameters to execute the SetDefaultAuthorizer service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTSetDefaultAuthorizerResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceAlreadyExists`.
 
 @see AWSIoTSetDefaultAuthorizerRequest
 @see AWSIoTSetDefaultAuthorizerResponse
 */
- (AWSTask<AWSIoTSetDefaultAuthorizerResponse *> *)setDefaultAuthorizer:(AWSIoTSetDefaultAuthorizerRequest *)request;

/**
 <p>Sets the default authorizer. This will be used if a websocket connection is made without specifying an authorizer.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">SetDefaultAuthorizer</a> action.</p>
 
 @param request A container for the necessary parameters to execute the SetDefaultAuthorizer service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceAlreadyExists`.
 
 @see AWSIoTSetDefaultAuthorizerRequest
 @see AWSIoTSetDefaultAuthorizerResponse
 */
- (void)setDefaultAuthorizer:(AWSIoTSetDefaultAuthorizerRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTSetDefaultAuthorizerResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Sets the specified version of the specified policy as the policy's default (operative) version. This action affects all certificates to which the policy is attached. To list the principals the policy is attached to, use the <a>ListPrincipalPolicies</a> action.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">SetDefaultPolicyVersion</a> action.</p>
 
 @param request A container for the necessary parameters to execute the SetDefaultPolicyVersion service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTSetDefaultPolicyVersionRequest
 */
- (AWSTask *)setDefaultPolicyVersion:(AWSIoTSetDefaultPolicyVersionRequest *)request;

/**
 <p>Sets the specified version of the specified policy as the policy's default (operative) version. This action affects all certificates to which the policy is attached. To list the principals the policy is attached to, use the <a>ListPrincipalPolicies</a> action.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">SetDefaultPolicyVersion</a> action.</p>
 
 @param request A container for the necessary parameters to execute the SetDefaultPolicyVersion service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTSetDefaultPolicyVersionRequest
 */
- (void)setDefaultPolicyVersion:(AWSIoTSetDefaultPolicyVersionRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Sets the logging options.</p><p>NOTE: use of this command is not recommended. Use <code>SetV2LoggingOptions</code> instead.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">SetLoggingOptions</a> action.</p>
 
 @param request A container for the necessary parameters to execute the SetLoggingOptions service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTSetLoggingOptionsRequest
 */
- (AWSTask *)setLoggingOptions:(AWSIoTSetLoggingOptionsRequest *)request;

/**
 <p>Sets the logging options.</p><p>NOTE: use of this command is not recommended. Use <code>SetV2LoggingOptions</code> instead.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">SetLoggingOptions</a> action.</p>
 
 @param request A container for the necessary parameters to execute the SetLoggingOptions service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTSetLoggingOptionsRequest
 */
- (void)setLoggingOptions:(AWSIoTSetLoggingOptionsRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Sets the logging level.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">SetV2LoggingLevel</a> action.</p>
 
 @param request A container for the necessary parameters to execute the SetV2LoggingLevel service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorNotConfigured`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTSetV2LoggingLevelRequest
 */
- (AWSTask *)setV2LoggingLevel:(AWSIoTSetV2LoggingLevelRequest *)request;

/**
 <p>Sets the logging level.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">SetV2LoggingLevel</a> action.</p>
 
 @param request A container for the necessary parameters to execute the SetV2LoggingLevel service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorNotConfigured`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTSetV2LoggingLevelRequest
 */
- (void)setV2LoggingLevel:(AWSIoTSetV2LoggingLevelRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Sets the logging options for the V2 logging service.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">SetV2LoggingOptions</a> action.</p>
 
 @param request A container for the necessary parameters to execute the SetV2LoggingOptions service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTSetV2LoggingOptionsRequest
 */
- (AWSTask *)setV2LoggingOptions:(AWSIoTSetV2LoggingOptionsRequest *)request;

/**
 <p>Sets the logging options for the V2 logging service.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">SetV2LoggingOptions</a> action.</p>
 
 @param request A container for the necessary parameters to execute the SetV2LoggingOptions service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTSetV2LoggingOptionsRequest
 */
- (void)setV2LoggingOptions:(AWSIoTSetV2LoggingOptionsRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Starts a task that applies a set of mitigation actions to the specified target.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">StartAuditMitigationActionsTask</a> action.</p>
 
 @param request A container for the necessary parameters to execute the StartAuditMitigationActionsTask service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTStartAuditMitigationActionsTaskResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorTaskAlreadyExists`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTStartAuditMitigationActionsTaskRequest
 @see AWSIoTStartAuditMitigationActionsTaskResponse
 */
- (AWSTask<AWSIoTStartAuditMitigationActionsTaskResponse *> *)startAuditMitigationActionsTask:(AWSIoTStartAuditMitigationActionsTaskRequest *)request;

/**
 <p>Starts a task that applies a set of mitigation actions to the specified target.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">StartAuditMitigationActionsTask</a> action.</p>
 
 @param request A container for the necessary parameters to execute the StartAuditMitigationActionsTask service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorTaskAlreadyExists`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTStartAuditMitigationActionsTaskRequest
 @see AWSIoTStartAuditMitigationActionsTaskResponse
 */
- (void)startAuditMitigationActionsTask:(AWSIoTStartAuditMitigationActionsTaskRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTStartAuditMitigationActionsTaskResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p> Starts a Device Defender ML Detect mitigation actions task. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">StartDetectMitigationActionsTask</a> action.</p>
 
 @param request A container for the necessary parameters to execute the StartDetectMitigationActionsTask service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTStartDetectMitigationActionsTaskResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorTaskAlreadyExists`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTStartDetectMitigationActionsTaskRequest
 @see AWSIoTStartDetectMitigationActionsTaskResponse
 */
- (AWSTask<AWSIoTStartDetectMitigationActionsTaskResponse *> *)startDetectMitigationActionsTask:(AWSIoTStartDetectMitigationActionsTaskRequest *)request;

/**
 <p> Starts a Device Defender ML Detect mitigation actions task. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">StartDetectMitigationActionsTask</a> action.</p>
 
 @param request A container for the necessary parameters to execute the StartDetectMitigationActionsTask service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorTaskAlreadyExists`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTStartDetectMitigationActionsTaskRequest
 @see AWSIoTStartDetectMitigationActionsTaskResponse
 */
- (void)startDetectMitigationActionsTask:(AWSIoTStartDetectMitigationActionsTaskRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTStartDetectMitigationActionsTaskResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Starts an on-demand Device Defender audit.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">StartOnDemandAuditTask</a> action.</p>
 
 @param request A container for the necessary parameters to execute the StartOnDemandAuditTask service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTStartOnDemandAuditTaskResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTStartOnDemandAuditTaskRequest
 @see AWSIoTStartOnDemandAuditTaskResponse
 */
- (AWSTask<AWSIoTStartOnDemandAuditTaskResponse *> *)startOnDemandAuditTask:(AWSIoTStartOnDemandAuditTaskRequest *)request;

/**
 <p>Starts an on-demand Device Defender audit.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">StartOnDemandAuditTask</a> action.</p>
 
 @param request A container for the necessary parameters to execute the StartOnDemandAuditTask service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTStartOnDemandAuditTaskRequest
 @see AWSIoTStartOnDemandAuditTaskResponse
 */
- (void)startOnDemandAuditTask:(AWSIoTStartOnDemandAuditTaskRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTStartOnDemandAuditTaskResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates a bulk thing provisioning task.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">StartThingRegistrationTask</a> action.</p>
 
 @param request A container for the necessary parameters to execute the StartThingRegistrationTask service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTStartThingRegistrationTaskResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTStartThingRegistrationTaskRequest
 @see AWSIoTStartThingRegistrationTaskResponse
 */
- (AWSTask<AWSIoTStartThingRegistrationTaskResponse *> *)startThingRegistrationTask:(AWSIoTStartThingRegistrationTaskRequest *)request;

/**
 <p>Creates a bulk thing provisioning task.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">StartThingRegistrationTask</a> action.</p>
 
 @param request A container for the necessary parameters to execute the StartThingRegistrationTask service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTStartThingRegistrationTaskRequest
 @see AWSIoTStartThingRegistrationTaskResponse
 */
- (void)startThingRegistrationTask:(AWSIoTStartThingRegistrationTaskRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTStartThingRegistrationTaskResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Cancels a bulk thing provisioning task.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">StopThingRegistrationTask</a> action.</p>
 
 @param request A container for the necessary parameters to execute the StopThingRegistrationTask service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTStopThingRegistrationTaskResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTStopThingRegistrationTaskRequest
 @see AWSIoTStopThingRegistrationTaskResponse
 */
- (AWSTask<AWSIoTStopThingRegistrationTaskResponse *> *)stopThingRegistrationTask:(AWSIoTStopThingRegistrationTaskRequest *)request;

/**
 <p>Cancels a bulk thing provisioning task.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">StopThingRegistrationTask</a> action.</p>
 
 @param request A container for the necessary parameters to execute the StopThingRegistrationTask service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTStopThingRegistrationTaskRequest
 @see AWSIoTStopThingRegistrationTaskResponse
 */
- (void)stopThingRegistrationTask:(AWSIoTStopThingRegistrationTaskRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTStopThingRegistrationTaskResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Adds to or modifies the tags of the given resource. Tags are metadata which can be used to manage a resource.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">TagResource</a> action.</p>
 
 @param request A container for the necessary parameters to execute the TagResource service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTTagResourceResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTTagResourceRequest
 @see AWSIoTTagResourceResponse
 */
- (AWSTask<AWSIoTTagResourceResponse *> *)tagResource:(AWSIoTTagResourceRequest *)request;

/**
 <p>Adds to or modifies the tags of the given resource. Tags are metadata which can be used to manage a resource.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">TagResource</a> action.</p>
 
 @param request A container for the necessary parameters to execute the TagResource service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTTagResourceRequest
 @see AWSIoTTagResourceResponse
 */
- (void)tagResource:(AWSIoTTagResourceRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTTagResourceResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Tests if a specified principal is authorized to perform an IoT action on a specified resource. Use this to test and debug the authorization behavior of devices that connect to the IoT device gateway.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">TestAuthorization</a> action.</p>
 
 @param request A container for the necessary parameters to execute the TestAuthorization service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTTestAuthorizationResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTTestAuthorizationRequest
 @see AWSIoTTestAuthorizationResponse
 */
- (AWSTask<AWSIoTTestAuthorizationResponse *> *)testAuthorization:(AWSIoTTestAuthorizationRequest *)request;

/**
 <p>Tests if a specified principal is authorized to perform an IoT action on a specified resource. Use this to test and debug the authorization behavior of devices that connect to the IoT device gateway.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">TestAuthorization</a> action.</p>
 
 @param request A container for the necessary parameters to execute the TestAuthorization service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorLimitExceeded`.
 
 @see AWSIoTTestAuthorizationRequest
 @see AWSIoTTestAuthorizationResponse
 */
- (void)testAuthorization:(AWSIoTTestAuthorizationRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTTestAuthorizationResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Tests a custom authorization behavior by invoking a specified custom authorizer. Use this to test and debug the custom authorization behavior of devices that connect to the IoT device gateway.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">TestInvokeAuthorizer</a> action.</p>
 
 @param request A container for the necessary parameters to execute the TestInvokeAuthorizer service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTTestInvokeAuthorizerResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidResponse`.
 
 @see AWSIoTTestInvokeAuthorizerRequest
 @see AWSIoTTestInvokeAuthorizerResponse
 */
- (AWSTask<AWSIoTTestInvokeAuthorizerResponse *> *)testInvokeAuthorizer:(AWSIoTTestInvokeAuthorizerRequest *)request;

/**
 <p>Tests a custom authorization behavior by invoking a specified custom authorizer. Use this to test and debug the custom authorization behavior of devices that connect to the IoT device gateway.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">TestInvokeAuthorizer</a> action.</p>
 
 @param request A container for the necessary parameters to execute the TestInvokeAuthorizer service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidResponse`.
 
 @see AWSIoTTestInvokeAuthorizerRequest
 @see AWSIoTTestInvokeAuthorizerResponse
 */
- (void)testInvokeAuthorizer:(AWSIoTTestInvokeAuthorizerRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTTestInvokeAuthorizerResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Transfers the specified certificate to the specified Amazon Web Services account.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">TransferCertificate</a> action.</p><p>You can cancel the transfer until it is acknowledged by the recipient.</p><p>No notification is sent to the transfer destination's account. It is up to the caller to notify the transfer target.</p><p>The certificate being transferred must not be in the ACTIVE state. You can use the <a>UpdateCertificate</a> action to deactivate it.</p><p>The certificate must not have any policies attached to it. You can use the <a>DetachPolicy</a> action to detach them.</p>
 
 @param request A container for the necessary parameters to execute the TransferCertificate service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTTransferCertificateResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorCertificateState`, `AWSIoTErrorTransferConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTTransferCertificateRequest
 @see AWSIoTTransferCertificateResponse
 */
- (AWSTask<AWSIoTTransferCertificateResponse *> *)transferCertificate:(AWSIoTTransferCertificateRequest *)request;

/**
 <p>Transfers the specified certificate to the specified Amazon Web Services account.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">TransferCertificate</a> action.</p><p>You can cancel the transfer until it is acknowledged by the recipient.</p><p>No notification is sent to the transfer destination's account. It is up to the caller to notify the transfer target.</p><p>The certificate being transferred must not be in the ACTIVE state. You can use the <a>UpdateCertificate</a> action to deactivate it.</p><p>The certificate must not have any policies attached to it. You can use the <a>DetachPolicy</a> action to detach them.</p>
 
 @param request A container for the necessary parameters to execute the TransferCertificate service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorCertificateState`, `AWSIoTErrorTransferConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTTransferCertificateRequest
 @see AWSIoTTransferCertificateResponse
 */
- (void)transferCertificate:(AWSIoTTransferCertificateRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTTransferCertificateResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Removes the given tags (metadata) from the resource.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UntagResource</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UntagResource service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTUntagResourceResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTUntagResourceRequest
 @see AWSIoTUntagResourceResponse
 */
- (AWSTask<AWSIoTUntagResourceResponse *> *)untagResource:(AWSIoTUntagResourceRequest *)request;

/**
 <p>Removes the given tags (metadata) from the resource.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UntagResource</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UntagResource service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTUntagResourceRequest
 @see AWSIoTUntagResourceResponse
 */
- (void)untagResource:(AWSIoTUntagResourceRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTUntagResourceResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Configures or reconfigures the Device Defender audit settings for this account. Settings include how audit notifications are sent and which audit checks are enabled or disabled.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateAccountAuditConfiguration</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateAccountAuditConfiguration service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTUpdateAccountAuditConfigurationResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateAccountAuditConfigurationRequest
 @see AWSIoTUpdateAccountAuditConfigurationResponse
 */
- (AWSTask<AWSIoTUpdateAccountAuditConfigurationResponse *> *)updateAccountAuditConfiguration:(AWSIoTUpdateAccountAuditConfigurationRequest *)request;

/**
 <p>Configures or reconfigures the Device Defender audit settings for this account. Settings include how audit notifications are sent and which audit checks are enabled or disabled.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateAccountAuditConfiguration</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateAccountAuditConfiguration service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateAccountAuditConfigurationRequest
 @see AWSIoTUpdateAccountAuditConfigurationResponse
 */
- (void)updateAccountAuditConfiguration:(AWSIoTUpdateAccountAuditConfigurationRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTUpdateAccountAuditConfigurationResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p> Updates a Device Defender audit suppression. </p>
 
 @param request A container for the necessary parameters to execute the UpdateAuditSuppression service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTUpdateAuditSuppressionResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateAuditSuppressionRequest
 @see AWSIoTUpdateAuditSuppressionResponse
 */
- (AWSTask<AWSIoTUpdateAuditSuppressionResponse *> *)updateAuditSuppression:(AWSIoTUpdateAuditSuppressionRequest *)request;

/**
 <p> Updates a Device Defender audit suppression. </p>
 
 @param request A container for the necessary parameters to execute the UpdateAuditSuppression service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateAuditSuppressionRequest
 @see AWSIoTUpdateAuditSuppressionResponse
 */
- (void)updateAuditSuppression:(AWSIoTUpdateAuditSuppressionRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTUpdateAuditSuppressionResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Updates an authorizer.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateAuthorizer</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateAuthorizer service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTUpdateAuthorizerResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateAuthorizerRequest
 @see AWSIoTUpdateAuthorizerResponse
 */
- (AWSTask<AWSIoTUpdateAuthorizerResponse *> *)updateAuthorizer:(AWSIoTUpdateAuthorizerRequest *)request;

/**
 <p>Updates an authorizer.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateAuthorizer</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateAuthorizer service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorLimitExceeded`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateAuthorizerRequest
 @see AWSIoTUpdateAuthorizerResponse
 */
- (void)updateAuthorizer:(AWSIoTUpdateAuthorizerRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTUpdateAuthorizerResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Updates information about the billing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateBillingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateBillingGroup service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTUpdateBillingGroupResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorVersionConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTUpdateBillingGroupRequest
 @see AWSIoTUpdateBillingGroupResponse
 */
- (AWSTask<AWSIoTUpdateBillingGroupResponse *> *)updateBillingGroup:(AWSIoTUpdateBillingGroupRequest *)request;

/**
 <p>Updates information about the billing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateBillingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateBillingGroup service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorVersionConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTUpdateBillingGroupRequest
 @see AWSIoTUpdateBillingGroupResponse
 */
- (void)updateBillingGroup:(AWSIoTUpdateBillingGroupRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTUpdateBillingGroupResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Updates a registered CA certificate.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateCACertificate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateCACertificate service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateCACertificateRequest
 */
- (AWSTask *)updateCACertificate:(AWSIoTUpdateCACertificateRequest *)request;

/**
 <p>Updates a registered CA certificate.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateCACertificate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateCACertificate service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateCACertificateRequest
 */
- (void)updateCACertificate:(AWSIoTUpdateCACertificateRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Updates the status of the specified certificate. This operation is idempotent.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateCertificate</a> action.</p><p>Certificates must be in the ACTIVE state to authenticate devices that use a certificate to connect to IoT.</p><p>Within a few minutes of updating a certificate from the ACTIVE state to any other state, IoT disconnects all devices that used that certificate to connect. Devices cannot use a certificate that is not in the ACTIVE state to reconnect.</p>
 
 @param request A container for the necessary parameters to execute the UpdateCertificate service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorCertificateState`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateCertificateRequest
 */
- (AWSTask *)updateCertificate:(AWSIoTUpdateCertificateRequest *)request;

/**
 <p>Updates the status of the specified certificate. This operation is idempotent.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateCertificate</a> action.</p><p>Certificates must be in the ACTIVE state to authenticate devices that use a certificate to connect to IoT.</p><p>Within a few minutes of updating a certificate from the ACTIVE state to any other state, IoT disconnects all devices that used that certificate to connect. Devices cannot use a certificate that is not in the ACTIVE state to reconnect.</p>
 
 @param request A container for the necessary parameters to execute the UpdateCertificate service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorCertificateState`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateCertificateRequest
 */
- (void)updateCertificate:(AWSIoTUpdateCertificateRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Updates a Device Defender detect custom metric. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateCustomMetric</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateCustomMetric service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTUpdateCustomMetricResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateCustomMetricRequest
 @see AWSIoTUpdateCustomMetricResponse
 */
- (AWSTask<AWSIoTUpdateCustomMetricResponse *> *)updateCustomMetric:(AWSIoTUpdateCustomMetricRequest *)request;

/**
 <p>Updates a Device Defender detect custom metric. </p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateCustomMetric</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateCustomMetric service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateCustomMetricRequest
 @see AWSIoTUpdateCustomMetricResponse
 */
- (void)updateCustomMetric:(AWSIoTUpdateCustomMetricRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTUpdateCustomMetricResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Updates the definition for a dimension. You cannot change the type of a dimension after it is created (you can delete it and recreate it).</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateDimension</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateDimension service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTUpdateDimensionResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTUpdateDimensionRequest
 @see AWSIoTUpdateDimensionResponse
 */
- (AWSTask<AWSIoTUpdateDimensionResponse *> *)updateDimension:(AWSIoTUpdateDimensionRequest *)request;

/**
 <p>Updates the definition for a dimension. You cannot change the type of a dimension after it is created (you can delete it and recreate it).</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateDimension</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateDimension service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTUpdateDimensionRequest
 @see AWSIoTUpdateDimensionResponse
 */
- (void)updateDimension:(AWSIoTUpdateDimensionRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTUpdateDimensionResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Updates values stored in the domain configuration. Domain configurations for default endpoints can't be updated.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateDomainConfiguration</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateDomainConfiguration service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTUpdateDomainConfigurationResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorCertificateValidation`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateDomainConfigurationRequest
 @see AWSIoTUpdateDomainConfigurationResponse
 */
- (AWSTask<AWSIoTUpdateDomainConfigurationResponse *> *)updateDomainConfiguration:(AWSIoTUpdateDomainConfigurationRequest *)request;

/**
 <p>Updates values stored in the domain configuration. Domain configurations for default endpoints can't be updated.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateDomainConfiguration</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateDomainConfiguration service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorCertificateValidation`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateDomainConfigurationRequest
 @see AWSIoTUpdateDomainConfigurationResponse
 */
- (void)updateDomainConfiguration:(AWSIoTUpdateDomainConfigurationRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTUpdateDomainConfigurationResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Updates a dynamic thing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateDynamicThingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateDynamicThingGroup service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTUpdateDynamicThingGroupResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorVersionConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidQuery`.
 
 @see AWSIoTUpdateDynamicThingGroupRequest
 @see AWSIoTUpdateDynamicThingGroupResponse
 */
- (AWSTask<AWSIoTUpdateDynamicThingGroupResponse *> *)updateDynamicThingGroup:(AWSIoTUpdateDynamicThingGroupRequest *)request;

/**
 <p>Updates a dynamic thing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateDynamicThingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateDynamicThingGroup service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorVersionConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidQuery`.
 
 @see AWSIoTUpdateDynamicThingGroupRequest
 @see AWSIoTUpdateDynamicThingGroupResponse
 */
- (void)updateDynamicThingGroup:(AWSIoTUpdateDynamicThingGroupRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTUpdateDynamicThingGroupResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Updates the event configurations.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateEventConfigurations</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateEventConfigurations service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTUpdateEventConfigurationsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTUpdateEventConfigurationsRequest
 @see AWSIoTUpdateEventConfigurationsResponse
 */
- (AWSTask<AWSIoTUpdateEventConfigurationsResponse *> *)updateEventConfigurations:(AWSIoTUpdateEventConfigurationsRequest *)request;

/**
 <p>Updates the event configurations.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateEventConfigurations</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateEventConfigurations service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorThrottling`.
 
 @see AWSIoTUpdateEventConfigurationsRequest
 @see AWSIoTUpdateEventConfigurationsResponse
 */
- (void)updateEventConfigurations:(AWSIoTUpdateEventConfigurationsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTUpdateEventConfigurationsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Updates the data for a fleet metric.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateFleetMetric</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateFleetMetric service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidQuery`, `AWSIoTErrorInvalidAggregation`, `AWSIoTErrorVersionConflict`, `AWSIoTErrorIndexNotReady`.
 
 @see AWSIoTUpdateFleetMetricRequest
 */
- (AWSTask *)updateFleetMetric:(AWSIoTUpdateFleetMetricRequest *)request;

/**
 <p>Updates the data for a fleet metric.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateFleetMetric</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateFleetMetric service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidQuery`, `AWSIoTErrorInvalidAggregation`, `AWSIoTErrorVersionConflict`, `AWSIoTErrorIndexNotReady`.
 
 @see AWSIoTUpdateFleetMetricRequest
 */
- (void)updateFleetMetric:(AWSIoTUpdateFleetMetricRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Updates the search configuration.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateIndexingConfiguration</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateIndexingConfiguration service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTUpdateIndexingConfigurationResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateIndexingConfigurationRequest
 @see AWSIoTUpdateIndexingConfigurationResponse
 */
- (AWSTask<AWSIoTUpdateIndexingConfigurationResponse *> *)updateIndexingConfiguration:(AWSIoTUpdateIndexingConfigurationRequest *)request;

/**
 <p>Updates the search configuration.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateIndexingConfiguration</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateIndexingConfiguration service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateIndexingConfigurationRequest
 @see AWSIoTUpdateIndexingConfigurationResponse
 */
- (void)updateIndexingConfiguration:(AWSIoTUpdateIndexingConfigurationRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTUpdateIndexingConfigurationResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Updates supported fields of the specified job.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateJob</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateJob service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTUpdateJobRequest
 */
- (AWSTask *)updateJob:(AWSIoTUpdateJobRequest *)request;

/**
 <p>Updates supported fields of the specified job.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateJob</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateJob service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorServiceUnavailable`.
 
 @see AWSIoTUpdateJobRequest
 */
- (void)updateJob:(AWSIoTUpdateJobRequest *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Updates the definition for the specified mitigation action.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateMitigationAction</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateMitigationAction service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTUpdateMitigationActionResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateMitigationActionRequest
 @see AWSIoTUpdateMitigationActionResponse
 */
- (AWSTask<AWSIoTUpdateMitigationActionResponse *> *)updateMitigationAction:(AWSIoTUpdateMitigationActionRequest *)request;

/**
 <p>Updates the definition for the specified mitigation action.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateMitigationAction</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateMitigationAction service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateMitigationActionRequest
 @see AWSIoTUpdateMitigationActionResponse
 */
- (void)updateMitigationAction:(AWSIoTUpdateMitigationActionRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTUpdateMitigationActionResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Updates a provisioning template.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateProvisioningTemplate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateProvisioningTemplate service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTUpdateProvisioningTemplateResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorConflictingResourceUpdate`.
 
 @see AWSIoTUpdateProvisioningTemplateRequest
 @see AWSIoTUpdateProvisioningTemplateResponse
 */
- (AWSTask<AWSIoTUpdateProvisioningTemplateResponse *> *)updateProvisioningTemplate:(AWSIoTUpdateProvisioningTemplateRequest *)request;

/**
 <p>Updates a provisioning template.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateProvisioningTemplate</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateProvisioningTemplate service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternalFailure`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorConflictingResourceUpdate`.
 
 @see AWSIoTUpdateProvisioningTemplateRequest
 @see AWSIoTUpdateProvisioningTemplateResponse
 */
- (void)updateProvisioningTemplate:(AWSIoTUpdateProvisioningTemplateRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTUpdateProvisioningTemplateResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Updates a role alias.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateRoleAlias</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateRoleAlias service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTUpdateRoleAliasResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateRoleAliasRequest
 @see AWSIoTUpdateRoleAliasResponse
 */
- (AWSTask<AWSIoTUpdateRoleAliasResponse *> *)updateRoleAlias:(AWSIoTUpdateRoleAliasRequest *)request;

/**
 <p>Updates a role alias.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateRoleAlias</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateRoleAlias service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorResourceNotFound`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateRoleAliasRequest
 @see AWSIoTUpdateRoleAliasResponse
 */
- (void)updateRoleAlias:(AWSIoTUpdateRoleAliasRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTUpdateRoleAliasResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Updates a scheduled audit, including which checks are performed and how often the audit takes place.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateScheduledAudit</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateScheduledAudit service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTUpdateScheduledAuditResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateScheduledAuditRequest
 @see AWSIoTUpdateScheduledAuditResponse
 */
- (AWSTask<AWSIoTUpdateScheduledAuditResponse *> *)updateScheduledAudit:(AWSIoTUpdateScheduledAuditRequest *)request;

/**
 <p>Updates a scheduled audit, including which checks are performed and how often the audit takes place.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateScheduledAudit</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateScheduledAudit service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateScheduledAuditRequest
 @see AWSIoTUpdateScheduledAuditResponse
 */
- (void)updateScheduledAudit:(AWSIoTUpdateScheduledAuditRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTUpdateScheduledAuditResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Updates a Device Defender security profile.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateSecurityProfile</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateSecurityProfile service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTUpdateSecurityProfileResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorVersionConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateSecurityProfileRequest
 @see AWSIoTUpdateSecurityProfileResponse
 */
- (AWSTask<AWSIoTUpdateSecurityProfileResponse *> *)updateSecurityProfile:(AWSIoTUpdateSecurityProfileRequest *)request;

/**
 <p>Updates a Device Defender security profile.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateSecurityProfile</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateSecurityProfile service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorVersionConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateSecurityProfileRequest
 @see AWSIoTUpdateSecurityProfileResponse
 */
- (void)updateSecurityProfile:(AWSIoTUpdateSecurityProfileRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTUpdateSecurityProfileResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Updates an existing stream. The stream version will be incremented by one.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateStream</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateStream service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTUpdateStreamResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateStreamRequest
 @see AWSIoTUpdateStreamResponse
 */
- (AWSTask<AWSIoTUpdateStreamResponse *> *)updateStream:(AWSIoTUpdateStreamRequest *)request;

/**
 <p>Updates an existing stream. The stream version will be incremented by one.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateStream</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateStream service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorResourceNotFound`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTUpdateStreamRequest
 @see AWSIoTUpdateStreamResponse
 */
- (void)updateStream:(AWSIoTUpdateStreamRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTUpdateStreamResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Updates the data for a thing.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateThing</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateThing service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTUpdateThingResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorVersionConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTUpdateThingRequest
 @see AWSIoTUpdateThingResponse
 */
- (AWSTask<AWSIoTUpdateThingResponse *> *)updateThing:(AWSIoTUpdateThingRequest *)request;

/**
 <p>Updates the data for a thing.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateThing</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateThing service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorVersionConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTUpdateThingRequest
 @see AWSIoTUpdateThingResponse
 */
- (void)updateThing:(AWSIoTUpdateThingRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTUpdateThingResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Update a thing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateThingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateThingGroup service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTUpdateThingGroupResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorVersionConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTUpdateThingGroupRequest
 @see AWSIoTUpdateThingGroupResponse
 */
- (AWSTask<AWSIoTUpdateThingGroupResponse *> *)updateThingGroup:(AWSIoTUpdateThingGroupRequest *)request;

/**
 <p>Update a thing group.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateThingGroup</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateThingGroup service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorVersionConflict`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTUpdateThingGroupRequest
 @see AWSIoTUpdateThingGroupResponse
 */
- (void)updateThingGroup:(AWSIoTUpdateThingGroupRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTUpdateThingGroupResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Updates the groups to which the thing belongs.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateThingGroupsForThing</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateThingGroupsForThing service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTUpdateThingGroupsForThingResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTUpdateThingGroupsForThingRequest
 @see AWSIoTUpdateThingGroupsForThingResponse
 */
- (AWSTask<AWSIoTUpdateThingGroupsForThingResponse *> *)updateThingGroupsForThing:(AWSIoTUpdateThingGroupsForThingRequest *)request;

/**
 <p>Updates the groups to which the thing belongs.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateThingGroupsForThing</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateThingGroupsForThing service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`, `AWSIoTErrorResourceNotFound`.
 
 @see AWSIoTUpdateThingGroupsForThingRequest
 @see AWSIoTUpdateThingGroupsForThingResponse
 */
- (void)updateThingGroupsForThing:(AWSIoTUpdateThingGroupsForThingRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTUpdateThingGroupsForThingResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Updates a topic rule destination. You use this to change the status, endpoint URL, or confirmation URL of the destination.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateTopicRuleDestination</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateTopicRuleDestination service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTUpdateTopicRuleDestinationResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorConflictingResourceUpdate`.
 
 @see AWSIoTUpdateTopicRuleDestinationRequest
 @see AWSIoTUpdateTopicRuleDestinationResponse
 */
- (AWSTask<AWSIoTUpdateTopicRuleDestinationResponse *> *)updateTopicRuleDestination:(AWSIoTUpdateTopicRuleDestinationRequest *)request;

/**
 <p>Updates a topic rule destination. You use this to change the status, endpoint URL, or confirmation URL of the destination.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">UpdateTopicRuleDestination</a> action.</p>
 
 @param request A container for the necessary parameters to execute the UpdateTopicRuleDestination service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInternal`, `AWSIoTErrorInvalidRequest`, `AWSIoTErrorServiceUnavailable`, `AWSIoTErrorUnauthorized`, `AWSIoTErrorConflictingResourceUpdate`.
 
 @see AWSIoTUpdateTopicRuleDestinationRequest
 @see AWSIoTUpdateTopicRuleDestinationResponse
 */
- (void)updateTopicRuleDestination:(AWSIoTUpdateTopicRuleDestinationRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTUpdateTopicRuleDestinationResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Validates a Device Defender security profile behaviors specification.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ValidateSecurityProfileBehaviors</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ValidateSecurityProfileBehaviors service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSIoTValidateSecurityProfileBehaviorsResponse`. On failed execution, `task.error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTValidateSecurityProfileBehaviorsRequest
 @see AWSIoTValidateSecurityProfileBehaviorsResponse
 */
- (AWSTask<AWSIoTValidateSecurityProfileBehaviorsResponse *> *)validateSecurityProfileBehaviors:(AWSIoTValidateSecurityProfileBehaviorsRequest *)request;

/**
 <p>Validates a Device Defender security profile behaviors specification.</p><p>Requires permission to access the <a href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awsiot.html#awsiot-actions-as-permissions">ValidateSecurityProfileBehaviors</a> action.</p>
 
 @param request A container for the necessary parameters to execute the ValidateSecurityProfileBehaviors service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSIoTErrorDomain` domain and the following error code: `AWSIoTErrorInvalidRequest`, `AWSIoTErrorThrottling`, `AWSIoTErrorInternalFailure`.
 
 @see AWSIoTValidateSecurityProfileBehaviorsRequest
 @see AWSIoTValidateSecurityProfileBehaviorsResponse
 */
- (void)validateSecurityProfileBehaviors:(AWSIoTValidateSecurityProfileBehaviorsRequest *)request completionHandler:(void (^ _Nullable)(AWSIoTValidateSecurityProfileBehaviorsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

@end

NS_ASSUME_NONNULL_END
