// func serv_timer_set @ 0059afd0 size=476

undefined4 serv_timer_set(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  void *__s;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  uVar5 = 0xffffffff;
  iVar1 = cw_ac_data_size_get();
  if (((param_1 != (int *)0x0) && (param_2 != 0)) && (iVar6 = 0, param_2 < 2)) {
    while (iVar6 < iVar1) {
      iVar7 = iVar6 * 0xc;
      iVar2 = FUN_00407fe0(*param_1 + iVar7);
      if (iVar2 == 0) {
        iVar6 = iVar6 + 1;
      }
      else {
        puVar3 = (undefined4 *)FUN_00408450(8,0x4f2);
        if (puVar3 == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *puVar3 = 1;
        puVar3[1] = param_3;
        __s = (void *)FUN_00408450(0x18,0x4f9);
        if (__s == (void *)0x0) {
          FUN_00407df0(puVar3);
          return 0xffffffff;
        }
        memset(__s,0,0x18);
        FUN_0051ad88(__s);
        *(undefined4 *)((int)__s + 0x10) = 1;
        *(undefined4 **)((int)__s + 0x14) = puVar3;
        iVar4 = param_1[2];
        iVar2 = FUN_00407fe0(*param_1 + iVar7);
        param_1[2] = iVar4 - iVar2;
        FUN_004082c0(__s,*param_1 + iVar7);
        iVar2 = cw_ac_manager_event_add(iVar6,__s);
        if (iVar2 == -1) {
          FUN_004082c0(*param_1 + iVar7,__s);
          iVar6 = param_1[2];
          iVar1 = FUN_00407fe0(*param_1 + iVar7);
          param_1[2] = iVar1 + iVar6;
          FUN_00407df0(__s);
          FUN_00407df0(puVar3);
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 != 0) {
            printf("[CW_ERROR]%32s():%4d insert manager event data to manager_queue failed.\n",
                   "serv_timer_set",0x50b);
            return 0xffffffff;
          }
          return 0xffffffff;
        }
        iVar6 = iVar6 + 1;
      }
    }
    uVar5 = 0;
  }
  return uVar5;
}

