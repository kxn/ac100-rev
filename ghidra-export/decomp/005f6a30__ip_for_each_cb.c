// func _ip_for_each_cb @ 005f6a30 size=644

/* WARNING: Type propagation algorithm not settling */

undefined4 _ip_for_each_cb(undefined4 param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *__nptr;
  int iVar5;
  int local_48 [6];
  undefined4 local_30;
  
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  local_30 = 0;
  if ((g_wserv_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> n_column = %d\r\n","_ip_for_each_cb",0x1c3,param_2);
  }
  iVar5 = 0;
  do {
    if (param_2 <= iVar5) {
      uVar4 = 0;
      iVar5 = wserv_db_ip_load(local_48);
      if (((iVar5 != 0) && (uVar4 = 1, g_wserv_error != 0)) &&
         (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
        pcVar2 = "<wserv>[error]%s(): %d  -> wserv_ip_entry_load() fail!\r\n";
        uVar3 = 0x1e1;
LAB_005f6c2c:
        uVar4 = 1;
        printf(pcVar2,"_ip_for_each_cb",uVar3);
      }
      return uVar4;
    }
    if (g_wserv_debug == 0) {
      pcVar2 = (char *)*param_4;
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        pcVar2 = (char *)*param_4;
      }
      else {
        printf("<wserv>[debug]%s(): %d  -> idx = %d, column_name[idx] = %s, column_value[idx] = %s\r\n"
               ,"_ip_for_each_cb",0x1c6,iVar5,*param_4,*param_3);
        pcVar2 = (char *)*param_4;
      }
    }
    if ((pcVar2 == (char *)0x0) || (__nptr = (char *)*param_3, __nptr == (char *)0x0)) {
      if (g_wserv_error == 0) {
        return 1;
      }
      iVar5 = is_target_debug_ap();
      if (iVar5 == 0) {
        return 1;
      }
      pcVar2 = "<wserv>[error]%s(): %d  -> column_name or column_value is null!\r\n";
      uVar3 = 0x1c9;
      goto LAB_005f6c2c;
    }
    iVar1 = strcmp(pcVar2,"id");
    if (iVar1 == 0) {
      local_48[0] = atoi(__nptr);
    }
    else {
      iVar1 = strcmp(pcVar2,"ip_addr");
      if (iVar1 == 0) {
        FUN_0051a7a8(__nptr,local_48 + 1);
      }
      else {
        iVar1 = strcmp(pcVar2,"relay");
        if (iVar1 == 0) {
          iVar1 = atoi(__nptr);
          local_30 = CONCAT13((char)iVar1,local_30._1_3_);
        }
        else {
          iVar1 = strcmp(pcVar2,"enable");
          if (iVar1 == 0) {
            iVar1 = strncmp(__nptr,"on",3);
            local_30._1_3_ = CONCAT12(iVar1 == 0,local_30._2_2_);
          }
        }
      }
    }
    iVar5 = iVar5 + 1;
    param_3 = param_3 + 1;
    param_4 = param_4 + 1;
  } while( true );
}

