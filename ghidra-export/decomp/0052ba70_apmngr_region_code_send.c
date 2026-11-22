// func apmngr_region_code_send @ 0052ba70 size=692

undefined4 apmngr_region_code_send(uint param_1,undefined1 param_2)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  undefined4 local_8a8;
  undefined4 local_8a4;
  undefined4 local_8a0;
  uint local_5e0;
  undefined4 local_5d0;
  undefined4 local_5cc;
  int local_5c8;
  undefined4 local_5c4;
  undefined1 auStack_5c0 [600];
  uint local_368;
  byte local_2ef;
  undefined4 local_2e8;
  undefined4 local_2e4;
  undefined4 local_2e0;
  undefined4 local_2dc;
  undefined1 local_2d8 [4];
  int local_2d4;
  undefined2 local_2d0;
  undefined1 local_17;
  
  param_1 = param_1 & 0xffff;
  local_5d0 = 0;
  local_5cc = 0;
  local_5c8 = 0;
  local_5c4 = 0;
  memset(&local_2e8,0,0x2d8);
  memset(auStack_5c0,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1,&local_2e8);
  if (iVar1 != 0) {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[APMNGR_ERROR]%s()/%d get ap entry failed id:%d\n","apmngr_region_code_send",0x497,
           param_1);
    return 0xffffffff;
  }
  local_5d0 = 0;
  local_5cc = 0;
  local_5c8 = 0;
  local_5c4 = 0;
  iVar1 = serv_wtp_address_arg_init(&local_5d0);
  if (iVar1 == 0) {
    local_8a8 = 0x15f0000;
    local_8a4 = 1;
    local_8a0 = 0x41;
    iVar1 = apmngr_db_get_addr_by_capacity(param_1,&local_5d0,1,1);
    if (iVar1 == 0) {
      if (local_5c8 == 0) {
        if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(&local_5d0), iVar1 != 0)) {
          printf("[APMNGR_DEBUG]%s()/%d AP %d not support region code\n","apmngr_region_code_send",
                 0x4a8,param_1);
        }
      }
      else {
        if ((((local_2d4 == 4) || (local_2d4 == 8)) || (local_2d4 == 6)) || (local_2d4 == 5)) {
          iVar1 = apmngr_db_entry_get_by_id(local_2d0,auStack_5c0);
          if (iVar1 != 0) {
            if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(&local_5d0), iVar1 != 0))
            {
              printf("[APMNGR_ERROR]%s()/%d get cap entry failed id:%d\n","apmngr_region_code_send",
                     0x4b2,param_1);
            }
            goto LAB_0052bbac;
          }
          if ((local_368 & 2) != 0) {
            local_5e0 = (uint)local_2ef;
            for (uVar2 = 0; uVar2 < 0x2c8; uVar2 = uVar2 + 1) {
              *(undefined1 *)((int)&local_8a8 + uVar2) = local_2d8[uVar2];
            }
            iVar1 = is_support_region_code(local_2e8,local_2e4,local_2e0,local_2dc);
            bVar3 = 0;
            if (iVar1 != 0) {
              bVar3 = local_2ef;
            }
            apmngr_db_set_cur_using_region_code(bVar3,param_1);
            param_2 = local_17;
          }
        }
        iVar1 = apmngr_pkt_region_code_pkt_send(&local_5d0,param_2);
        if (iVar1 != 0) {
          if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[APMNGR_ERROR]%s()/%d Failed to send region code packet.\n",
                   "apmngr_region_code_send",0x4c7);
          }
          goto LAB_0052bbac;
        }
      }
      serv_wtp_address_arg_destroy(&local_5d0);
      return 0;
    }
  }
LAB_0052bbac:
  serv_wtp_address_arg_destroy(&local_5d0);
  return 0xffffffff;
}

