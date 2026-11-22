// func serv_user_defined_packet_send @ 0059adb4 size=484

undefined4 serv_user_defined_packet_send(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  void *__s;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  
  uVar4 = 0xffffffff;
  iVar1 = cw_ac_data_size_get();
  if ((param_1 != (int *)0x0) && (iVar6 = 0, param_2 != 0)) {
    while (iVar6 < iVar1) {
      iVar7 = iVar6 * 0xc;
      iVar2 = FUN_00407fe0(*param_1 + iVar7);
      if (iVar2 == 0) {
        iVar6 = iVar6 + 1;
      }
      else {
        puVar3 = (undefined4 *)cw_user_defined_send_pkt_create(param_2);
        if (puVar3 == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        __s = (void *)FUN_00408450(0x18,0x494);
        if (__s == (void *)0x0) {
          *puVar3 = 1;
          cw_user_defined_send_pkt_destroy(puVar3);
          return 0xffffffff;
        }
        memset(__s,0,0x18);
        FUN_0051ad88(__s);
        *(undefined4 *)((int)__s + 0x10) = 3;
        *(undefined4 **)((int)__s + 0x14) = puVar3;
        iVar5 = param_1[2];
        iVar2 = FUN_00407fe0(*param_1 + iVar7);
        param_1[2] = iVar5 - iVar2;
        FUN_004082c0(__s,*param_1 + iVar7);
        uVar8 = FUN_00524078();
        *(undefined8 *)(puVar3 + 2) = uVar8;
        iVar2 = cw_ac_manager_event_add(iVar6,__s);
        if (iVar2 == -1) {
          FUN_004082c0(*param_1 + iVar7,__s);
          iVar6 = param_1[2];
          iVar1 = FUN_00407fe0(*param_1 + iVar7);
          param_1[2] = iVar1 + iVar6;
          FUN_00407df0(__s);
          *puVar3 = 1;
          cw_user_defined_send_pkt_destroy(puVar3);
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 != 0) {
            printf("[CW_ERROR]%32s():%4d insert manager event data to manager_queue failed.\n",
                   "serv_user_defined_packet_send",0x4ac);
            return 0xffffffff;
          }
          return 0xffffffff;
        }
        iVar6 = iVar6 + 1;
      }
    }
    uVar4 = 0;
  }
  return uVar4;
}

