#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <CL/cl.h>

#define MAX_SOURCE_SIZE 1000

int main() {
    int n;
    const char *programSource = "__kernel void onesComplement(__global char *input, __global char *output) {  int idx = get_global_id(0); output[idx] = (input[idx] == '0') ? '1' : '0'; }";

    char *inputArray = NULL; // Input array
    char *outputArray = NULL; // Output array

    printf("Enter the number of binary numbers: ");
    scanf("%d", &n);

    // Allocate memory for input and output arrays
    inputArray = (char *)malloc(n * sizeof(char));
    outputArray = (char *)malloc(n * sizeof(char));

    printf("Enter the binary numbers:\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &inputArray[i]);
    }

    // Use this to check the output of each API call
    cl_int status;

    // STEP 1: Discover and initialize the platforms

    cl_uint numPlatforms = 0;
    cl_platform_id *platforms = NULL;
    status = clGetPlatformIDs(0, NULL, &numPlatforms);
    platforms = (cl_platform_id *)malloc(numPlatforms * sizeof(cl_platform_id));
    status = clGetPlatformIDs(numPlatforms, platforms, NULL);

    // STEP 2: Discover and initialize the devices

    cl_uint numDevices = 0;
    cl_device_id *devices = NULL;
    status = clGetDeviceIDs(platforms[0], CL_DEVICE_TYPE_GPU, 0, NULL, &numDevices);
    devices = (cl_device_id *)malloc(numDevices * sizeof(cl_device_id));
    status = clGetDeviceIDs(platforms[0], CL_DEVICE_TYPE_GPU, numDevices, devices, NULL);

    // STEP 3: Create a context

    cl_context context = NULL;
    context = clCreateContext(NULL, numDevices, devices, NULL, NULL, &status);

    // STEP 4: Create a command queue

    cl_command_queue cmdQueue;
    cmdQueue = clCreateCommandQueue(context, devices[0], 0, &status);

    // STEP 5: Create device buffers

    cl_mem bufferInput;
    cl_mem bufferOutput;

    bufferInput = clCreateBuffer(context, CL_MEM_READ_ONLY, n * sizeof(char), NULL, &status);
    bufferOutput = clCreateBuffer(context, CL_MEM_WRITE_ONLY, n * sizeof(char), NULL, &status);

    // STEP 6: Write host data to device buffers

    status = clEnqueueWriteBuffer(cmdQueue, bufferInput, CL_TRUE, 0, n * sizeof(char), inputArray, 0, NULL, NULL);

    // STEP 7: Create and compile the program

    cl_program program = clCreateProgramWithSource(context, 1, (const char **)&programSource, NULL, &status);
    status = clBuildProgram(program, numDevices, devices, NULL, NULL, NULL);

    // STEP 8: Create the kernel

    cl_kernel kernel = clCreateKernel(program, "onesComplement", &status);

    // STEP 9: Set the kernel arguments

    status = clSetKernelArg(kernel, 0, sizeof(cl_mem), &bufferInput);
    status |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &bufferOutput);

    // STEP 10: Configure the work-item structure

    size_t globalWorkSize[1];
    globalWorkSize[0] = n;

    // STEP 11: Enqueue the kernel for execution

    status = clEnqueueNDRangeKernel(cmdQueue, kernel, 1, NULL, globalWorkSize, NULL, 0, NULL, NULL);

    // STEP 12: Read the output buffer back to the host

    status = clEnqueueReadBuffer(cmdQueue, bufferOutput, CL_TRUE, 0, n * sizeof(char), outputArray, 0, NULL, NULL);

    // Print the output array
    printf("Output (One's complement):\n");
    for (int i = 0; i < n; i++) {
        printf("%c => %c\n", inputArray[i], outputArray[i]);
    }

    // STEP 13: Release OpenCL resources

    clReleaseKernel(kernel);
    clReleaseProgram(program);
    clReleaseCommandQueue(cmdQueue);
    clReleaseMemObject(bufferInput);
    clReleaseMemObject(bufferOutput);
    clReleaseContext(context);

    // Free host resources
    free(inputArray);
    free(outputArray);
    free(platforms);
    free(devices);

    return 0;
}
