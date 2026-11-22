// func rdmngr_db_get_same_freq_type_peer_radio @ 0061f818 size=456

undefined4
rdmngr_db_get_same_freq_type_peer_radio(undefined4 param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  char local_res8;
  int in_stack_00000054;
  int in_stack_00000058;
  int *in_stack_0000005c;
  undefined2 local_80;
  undefined2 local_7e;
  undefined1 auStack_7c [8];
  char local_74;
  
  uVar3 = 0xffffffff;
  memset(auStack_7c,0,0x54);
  if (in_stack_00000054 != 0) {
    local_80 = *(undefined2 *)(in_stack_00000054 + 0x44);
    local_res8 = (char)((uint)param_3 >> 0x18);
    local_7e = *(undefined2 *)(in_stack_00000054 + 0x46);
    iVar1 = rdmngr_db_get_ap_radio_cnt
                      (*(undefined4 *)(in_stack_00000054 + 0x40),in_stack_00000054 + 0x218,&local_80
                      );
    if (iVar1 < 0) {
      if ((rdmngr_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
        printf("[RDMNGR_ERROR]%s()/%d rdmngr_db_get_ap_same_freq_type_peer_radio_cnt fail, rd_cnt=%d.\n"
               ,"rdmngr_db_get_same_freq_type_peer_radio",0x80f,iVar1);
      }
    }
    else {
      uVar3 = 0;
      if (iVar1 != 0) {
        uVar4 = 1;
        iVar5 = 0;
        do {
          if ((param_2 & 0xf) != uVar4) {
            if (7 < iVar5) {
              if ((rdmngr_warning_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                printf("[RDMNGR_WARNING]%s()/%d Warning,link_cnt exceeds the max_radios_cnt %d\n",
                       "rdmngr_db_get_same_freq_type_peer_radio",0x822,8);
              }
              break;
            }
            rdmngr_db_rd_entry_get
                      (uVar4 & 0xf | (uint)*(ushort *)(in_stack_00000054 + 0x10) << 4,auStack_7c);
            if (local_74 == local_res8) {
              iVar2 = iVar5 * 0x54;
              iVar5 = iVar5 + 1;
              memcpy((void *)(in_stack_00000058 + iVar2),auStack_7c,0x54);
            }
          }
          uVar4 = uVar4 + 1;
        } while ((int)uVar4 <= iVar1);
        uVar3 = 0;
        *in_stack_0000005c = iVar5;
      }
    }
  }
  return uVar3;
}

