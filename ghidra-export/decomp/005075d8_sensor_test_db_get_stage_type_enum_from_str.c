// func sensor_test_db_get_stage_type_enum_from_str @ 005075d8 size=400

undefined4 sensor_test_db_get_stage_type_enum_from_str(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_1 != (char *)0x0) {
    uVar2 = 1;
    iVar1 = strcmp(param_1,"dns");
    if (iVar1 != 0) {
      uVar2 = 2;
      iVar1 = strcmp(param_1,"arp");
      if (iVar1 != 0) {
        uVar2 = 3;
        iVar1 = strcmp(param_1,"icmp");
        if ((iVar1 != 0) && (iVar1 = strcmp(param_1,"radius"), iVar1 != 0)) {
          uVar2 = 5;
          iVar1 = strcmp(param_1,"tcp");
          if (iVar1 != 0) {
            uVar2 = 6;
            iVar1 = strcmp(param_1,"http");
            if (iVar1 != 0) {
              uVar2 = 7;
              iVar1 = strcmp(param_1,"ftp");
              if (iVar1 != 0) {
                uVar2 = 8;
                iVar1 = strcmp(param_1,"scan");
                if (iVar1 != 0) {
                  uVar2 = 9;
                  iVar1 = strcmp(param_1,"auth");
                  if (iVar1 != 0) {
                    uVar2 = 10;
                    iVar1 = strcmp(param_1,"assoc");
                    if (iVar1 != 0) {
                      uVar2 = 0xb;
                      iVar1 = strcmp(param_1,"encryption");
                      if (iVar1 != 0) {
                        uVar2 = 0xc;
                        iVar1 = strcmp(param_1,"dhcp");
                        if (iVar1 != 0) {
                          uVar2 = 0xd;
                          iVar1 = strcmp(param_1,"speed");
                          if (iVar1 != 0) {
                            uVar2 = 0;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar2;
}

