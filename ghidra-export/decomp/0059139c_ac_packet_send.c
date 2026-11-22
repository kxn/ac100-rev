// func ac_packet_send @ 0059139c size=480

undefined4 ac_packet_send(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined8 uVar5;
  
  if (param_1 == 0) {
    uVar3 = 0x21d;
    pcVar4 = "NULL != session";
  }
  else {
    if (param_2 != 0) {
      iVar1 = cw_pkt_buf_create(0xcc00);
      if (iVar1 != 0) {
        iVar2 = (**(code **)(*(int *)(param_1 + 0xb0) + 4))(iVar1,param_2);
        if (iVar2 != -1) {
          uVar3 = ac_packet_buf_send(param_1,iVar1);
          iVar2 = is_store_snapshot();
          if (iVar2 != 0) {
            iVar2 = create_new_pkt_snapshot(3,*(undefined4 *)(param_1 + 0xc));
            get_pkt_info(iVar2,param_2);
            if (iVar2 != 0) {
              if (*(undefined4 **)(iVar2 + 0x58) != (undefined4 *)0x0) {
                **(undefined4 **)(iVar2 + 0x58) = 0;
                *(undefined1 *)(*(int *)(iVar2 + 0x58) + 4) = 0;
                *(undefined4 *)(*(int *)(iVar2 + 0x58) + 8) = 0;
              }
              uVar5 = FUN_00524078();
              *(undefined8 *)(iVar2 + 0x10) = uVar5;
              memcpy((void *)(iVar2 + 0x2c),(void *)(param_1 + 0x14),6);
            }
          }
          cw_pkt_buf_destroy(iVar1);
          return uVar3;
        }
        if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[CW_ERROR]%32s():%4d assemble discovery request failed\n","ac_packet_send",0x22f);
        }
        cw_pkt_buf_destroy(iVar1);
        return 0xffffffff;
      }
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      printf("[CW_ERROR]%32s():%4d malloc failed.\n","ac_packet_send",0x228);
      return 0xffffffff;
    }
    uVar3 = 0x21e;
    pcVar4 = "NULL != packet";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","ac_packet_send",uVar3,pcVar4);
  return 0xffffffff;
}

