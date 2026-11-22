// func apmngr_db_str_to_role @ 0053493c size=252

undefined4 apmngr_db_str_to_role(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(param_1,"cap");
  uVar2 = 1;
  if (iVar1 != 0) {
    iVar1 = strcmp(param_1,"cap_xvr");
    uVar2 = 2;
    if (iVar1 != 0) {
      iVar1 = strcmp(param_1,"cap_router");
      uVar2 = 3;
      if (iVar1 != 0) {
        iVar1 = strcmp(param_1,"re_ap");
        uVar2 = 4;
        if (iVar1 != 0) {
          iVar1 = strcmp(param_1,"re_router");
          uVar2 = 5;
          if (iVar1 != 0) {
            iVar1 = strcmp(param_1,"re_xvr");
            uVar2 = 8;
            if (iVar1 != 0) {
              iVar1 = strcmp(param_1,"re_mesh2_router");
              uVar2 = 6;
              if (iVar1 != 0) {
                iVar1 = strcmp(param_1,"sensor");
                uVar2 = 7;
                if (iVar1 != 0) {
                  iVar1 = strcmp(param_1,"vap");
                  uVar2 = 2;
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
  return uVar2;
}

