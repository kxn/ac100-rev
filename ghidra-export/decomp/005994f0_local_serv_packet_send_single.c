// func local_serv_packet_send_single @ 005994f0 size=552

undefined4
local_serv_packet_send_single
          (int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  void *__s;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  
  uVar4 = 0xffffffff;
  iVar1 = cw_ac_data_size_get();
  uVar5 = uVar4;
  if ((((param_1 != (int *)0x0) && (param_2 != (int *)0x0)) && (uVar5 = 0xffffffff, *param_2 != 0))
     && (iVar7 = 0, uVar5 = uVar4, *(short *)(param_2 + 1) != 0)) {
    while (iVar7 < iVar1) {
      iVar8 = iVar7 * 0xc;
      iVar2 = FUN_00407fe0(*param_1 + iVar8);
      if (iVar2 == 0) {
        iVar7 = iVar7 + 1;
      }
      else {
        iVar2 = cw_send_pkt_create(param_2[2],param_5);
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        cw_send_pkt_retransmit_set(iVar2,param_3);
        cw_send_pkt_retransmit_interval_set(iVar2,param_4);
        cw_send_pkt_buffer_set(iVar2,*param_2,*(undefined2 *)(param_2 + 1));
        __s = (void *)FUN_00408450(0x18,0x100);
        if (__s == (void *)0x0) {
          *(undefined4 *)(iVar2 + 8) = 1;
          cw_send_pkt_destroy(iVar2);
          return 0xffffffff;
        }
        memset(__s,0,0x18);
        FUN_0051ad88(__s);
        *(undefined4 *)((int)__s + 0x10) = 0;
        *(int *)((int)__s + 0x14) = iVar2;
        iVar6 = param_1[2];
        iVar3 = FUN_00407fe0(*param_1 + iVar8);
        param_1[2] = iVar6 - iVar3;
        FUN_004082c0(__s,*param_1 + iVar8);
        uVar9 = FUN_00524078();
        *(undefined8 *)(iVar2 + 0x40) = uVar9;
        iVar3 = cw_ac_manager_event_add(iVar7,__s);
        if (iVar3 == -1) {
          FUN_004082c0(*param_1 + iVar8,__s);
          iVar7 = param_1[2];
          iVar1 = FUN_00407fe0(*param_1 + iVar8);
          param_1[2] = iVar1 + iVar7;
          FUN_00407df0(__s);
          *(undefined4 *)(iVar2 + 8) = 1;
          cw_send_pkt_destroy(iVar2);
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 != 0) {
            printf("[CW_ERROR]%32s():%4d insert manager event data to manager_queue failed.\n",
                   "local_serv_packet_send_single",0x118);
            return 0xffffffff;
          }
          return 0xffffffff;
        }
        iVar7 = iVar7 + 1;
      }
    }
    uVar5 = 0;
  }
  return uVar5;
}

