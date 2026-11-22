// func sensor_test_db_get_test_type_enum_from_str @ 005074d0 size=264

undefined4 sensor_test_db_get_test_type_enum_from_str(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xff;
  if (param_1 != (char *)0x0) {
    iVar1 = strcmp(param_1,"onboarding");
    uVar2 = 0;
    if (iVar1 != 0) {
      iVar1 = strcmp(param_1,"dns");
      uVar2 = 1;
      if (iVar1 != 0) {
        iVar1 = strcmp(param_1,"hostaccess");
        uVar2 = 2;
        if (iVar1 != 0) {
          iVar1 = strcmp(param_1,"radius");
          uVar2 = 3;
          if (iVar1 != 0) {
            iVar1 = strcmp(param_1,"mail");
            uVar2 = 4;
            if (iVar1 != 0) {
              iVar1 = strcmp(param_1,"web");
              uVar2 = 5;
              if (iVar1 != 0) {
                iVar1 = strcmp(param_1,"ftp");
                uVar2 = 6;
                if (iVar1 != 0) {
                  iVar1 = strcmp(param_1,"speed");
                  uVar2 = 7;
                  if (iVar1 != 0) {
                    iVar1 = strcmp(param_1,"delayloss");
                    uVar2 = 8;
                    if (iVar1 != 0) {
                      uVar2 = 0xff;
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

