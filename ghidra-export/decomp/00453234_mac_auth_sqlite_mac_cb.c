// func mac_auth_sqlite_mac_cb @ 00453234 size=532

undefined4
mac_auth_sqlite_mac_cb(undefined4 param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *__s1;
  int iVar5;
  int local_d0;
  char acStack_cc [156];
  undefined1 auStack_30 [8];
  
  memset(&local_d0,0,0xa8);
  if (macauth_debug_switch != 0) {
    printf("[MACAUTH_DEBUG]%s()/%d column is %d\n","mac_auth_sqlite_mac_cb",0x40b,param_2);
  }
  iVar5 = 0;
  do {
    if (param_2 <= iVar5) {
      uVar4 = 0;
      iVar5 = mac_auth_db_load_mac_service(&local_d0);
      if ((iVar5 != 0) && (uVar4 = 1, macauth_err_switch != 0)) {
        pcVar2 = "[MACAUTH_ERROR]%s()/%d mac_auth_db_load_mac_service() failed.\n";
        uVar3 = 0x42e;
LAB_004533e0:
        uVar4 = 1;
        printf(pcVar2,"mac_auth_sqlite_mac_cb",uVar3);
      }
      return uVar4;
    }
    pcVar2 = (char *)*param_3;
    if ((pcVar2 == (char *)0x0) || (__s1 = (char *)*param_4, __s1 == (char *)0x0)) {
      if (macauth_err_switch == 0) {
        return 1;
      }
      pcVar2 = "[MACAUTH_ERROR]%s()/%d column value or name is null.\n";
      uVar3 = 0x411;
      goto LAB_004533e0;
    }
    iVar1 = strcmp(__s1,"id");
    if (iVar1 == 0) {
      local_d0 = atoi(pcVar2);
    }
    else {
      iVar1 = strcmp(__s1,"mac");
      if (iVar1 == 0) {
        mac_auth_mac_parse(pcVar2,auStack_30);
      }
      else {
        iVar1 = strcmp(__s1,"name");
        if (iVar1 == 0) {
          strncpy(acStack_cc,pcVar2,0x9b);
        }
        else {
          iVar1 = strcmp(__s1,"key");
          if (iVar1 != 0) {
            if (macauth_err_switch == 0) {
              return 1;
            }
            printf("[MACAUTH_ERROR]%s()/%d Invalid column_name[%s]\n","mac_auth_sqlite_mac_cb",0x427
                   ,__s1);
            return 1;
          }
        }
      }
    }
    iVar5 = iVar5 + 1;
    param_4 = param_4 + 1;
    param_3 = param_3 + 1;
  } while( true );
}

