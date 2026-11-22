// func serv_session_delete @ 0059b1ac size=400

undefined4 serv_session_delete(int *param_1)

{
  int iVar1;
  int iVar2;
  void *__s;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar3 = 0xffffffff;
  iVar1 = cw_ac_data_size_get();
  if (param_1 != (int *)0x0) {
    iVar5 = 0;
    while (iVar5 < iVar1) {
      iVar6 = iVar5 * 0xc;
      iVar2 = FUN_00407fe0(*param_1 + iVar6);
      if (iVar2 == 0) {
        iVar5 = iVar5 + 1;
      }
      else {
        __s = (void *)FUN_00408450(0x18,0x52c);
        if (__s == (void *)0x0) {
          return 0xffffffff;
        }
        memset(__s,0,0x18);
        FUN_0051ad88(__s);
        *(undefined4 *)((int)__s + 0x10) = 2;
        iVar4 = param_1[2];
        iVar2 = FUN_00407fe0(*param_1 + iVar6);
        param_1[2] = iVar4 - iVar2;
        FUN_004082c0(__s,*param_1 + iVar6);
        iVar2 = cw_ac_manager_event_add(iVar5,__s);
        if (iVar2 == -1) {
          FUN_004082c0(*param_1 + iVar6,__s);
          iVar5 = param_1[2];
          iVar1 = FUN_00407fe0(*param_1 + iVar6);
          param_1[2] = iVar1 + iVar5;
          FUN_00407df0(__s);
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          printf("[CW_ERROR]%32s():%4d insert manager event data to manager_queue failed.\n",
                 "serv_session_delete",0x53b);
          return 0xffffffff;
        }
        iVar5 = iVar5 + 1;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}

