// func apmngr_ap_disconnect @ 0052ecfc size=644

undefined4 apmngr_ap_disconnect(ushort *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_310;
  undefined4 local_30c;
  undefined4 local_308;
  undefined4 local_304;
  undefined1 auStack_300 [16];
  undefined2 local_2f0;
  int local_2ec;
  undefined1 auStack_2b8 [548];
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined2 local_80;
  int local_54;
  
  uVar3 = 0xffffffff;
  memset(auStack_300,0,0x2d8);
  local_310 = 0;
  local_30c = 0;
  local_308 = 0;
  local_304 = 0;
  if ((param_1 != (ushort *)0x0) && (0 < param_2)) {
    iVar1 = serv_wtp_address_arg_init(&local_310);
    if (iVar1 == 0) {
      iVar1 = 0;
      do {
        iVar2 = apmngr_db_entry_get_by_id(*param_1,auStack_300);
        if (iVar2 == 0) {
          if (local_2ec == 5) {
            if (local_54 != 0) {
              iVar2 = apmngr_db_get_cap_addr(local_2f0,&local_310,1);
              if (iVar2 == 0) goto LAB_0052eef8;
              if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                uVar3 = 0x9e7;
                goto LAB_0052eec4;
              }
            }
          }
          else if (local_54 != 0) {
            iVar2 = serv_wtp_address_arg_add
                              (&local_310,local_94,local_90,local_8c,local_88,local_84,local_80,
                               auStack_2b8,0);
            if (iVar2 == 0) {
LAB_0052eef8:
              uVar3 = 4;
              if (param_3 == 0) {
                uVar3 = 0;
              }
              apmngr_db_ap_reset_op_set(*param_1,uVar3);
            }
            else if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              uVar3 = 0x9d9;
LAB_0052eec4:
              printf("[APMNGR_ERROR]%s()/%d Failed to add entry ip-addr to struct.\n",
                     "apmngr_ap_disconnect",uVar3);
            }
          }
        }
        else {
          if ((apmngr_warning_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("[APMNGR_WARNING]%s()/%d Failed to find the entry(%d).\n","apmngr_ap_disconnect",
                   0x9cc,(uint)*param_1);
          }
          *param_1 = 0xffff;
        }
        iVar1 = iVar1 + 1;
        param_1 = param_1 + 1;
      } while (iVar1 != param_2);
      iVar1 = apmngr_pkt_reset_pkt_send(&local_310,1);
      if (((iVar1 != 0) && (apmngr_warning_switch != '\0')) &&
         (iVar1 = is_target_debug_ap(&local_310), iVar1 != 0)) {
        printf("[APMNGR_WARNING]%s()/%d Send Reset-Packet failed, delete ap-entry now.\n",
               "apmngr_ap_disconnect",0x9f3);
      }
      uVar3 = 0;
      serv_wtp_address_arg_destroy(&local_310);
    }
    else {
      serv_wtp_address_arg_destroy(&local_310);
    }
  }
  return uVar3;
}

