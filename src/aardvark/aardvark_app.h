#ifndef AARDVARK_APP_H
#define AARDVARK_APP_H

#include "aardvark.h"

extern int aa_detect(void);
extern int aa_i2c_file(int port, u8 addr, char *filename);
extern int aa_i2c_slave(int port, u8 addr, int timeout_ms);
extern int aa_smb_slave_poll(int port, u8 addr, int timeout_ms);

#endif // ~ AARDVARK_APP_H