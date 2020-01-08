//
//  Macros.h
//  IPFinal
//
//  Created by apple on 2020/1/8.
//  Copyright © 2020 aiofwa. All rights reserved.
//

#ifndef Macros_h
#define Macros_h


#define LOG(fmt, ...) printf("%s:%d: " fmt, __FILE__, __LINE__, ##__VA_ARGS__); printf("\n")

#endif /* Macros_h */
