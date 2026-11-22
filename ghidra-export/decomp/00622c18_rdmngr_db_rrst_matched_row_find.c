// func rdmngr_db_rrst_matched_row_find @ 00622c18 size=668

undefined4
rdmngr_db_rrst_matched_row_find
          (undefined4 param_1,byte param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined1 uStackX_a;
  short local_resc;
  undefined4 in_stack_0000004c;
  byte in_stack_00000057;
  byte in_stack_0000005b;
  undefined4 *in_stack_0000005c;
  int in_stack_00000060;
  undefined1 *in_stack_00000064;
  void *in_stack_00000068;
  int local_80 [20];
  uint local_30;
  uint local_2c;
  
  local_2c = (uint)in_stack_00000057;
  uVar3 = 0xffffffff;
  memset(local_80,0,0x50);
  local_80[0] = -1;
  if ((in_stack_0000005c != (undefined4 *)0x0) && (0 < in_stack_00000060)) {
    local_30 = 1 << (in_stack_0000005b & 0x1f);
    iVar7 = 0;
    uVar4 = 0;
    do {
      iVar1 = rdmngr_db_check_fit_row_rrst_feature_involved(local_2c,*in_stack_0000005c);
      uVar5 = uVar4;
      if (((iVar1 != 0) && ((local_30 & in_stack_0000005c[1]) != 0)) &&
         (*(char *)(in_stack_0000005c + 2) != '\0')) {
        if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[RDMNGR_DEBUG]%s()/%d src_rrst[%d].related_radio_cnt=%d\n",
                 "rdmngr_db_rrst_matched_row_find",0x1521,iVar7,
                 (uint)*(byte *)(in_stack_0000005c + 2));
        }
        puVar6 = in_stack_0000005c;
        for (iVar1 = 0; iVar1 < (int)(uint)*(byte *)(in_stack_0000005c + 2); iVar1 = iVar1 + 1) {
          if (((param_2 & 0xf) == *(byte *)(puVar6 + 0x26)) &&
             (iVar2 = rdmngr_db_check_fit_row_rrst_radio_abstract_status
                                (in_stack_0000004c._2_1_ != '\x01' &&
                                 in_stack_0000004c._2_1_ != '\x04',puVar6[0xb]), iVar2 != 0)) {
            uStackX_a = (undefined1)((uint)param_3 >> 8);
            iVar2 = rdmngr_db_check_fit_row_rrst_bandwidth
                              (uStackX_a,*(undefined1 *)((int)puVar6 + 0x99));
            if (iVar2 != 0) {
              local_resc = (short)((uint)param_4 >> 0x10);
              iVar2 = rdmngr_db_check_fit_row_rrst_channel
                                ((int)local_resc,(int)in_stack_0000005c + iVar1 * 0x74 + 0x32);
              if (iVar2 != 0) {
                if (0x13 < uVar4) {
                  if (rdmngr_err_switch == 0) {
                    return 0xffffffff;
                  }
                  iVar7 = is_target_debug_ap();
                  if (iVar7 == 0) {
                    return 0xffffffff;
                  }
                  printf("[RDMNGR_ERROR]%s()/%d invalid pre_matched_row_cnt exceeds src_rrst row max cnt\n"
                         ,"rdmngr_db_rrst_matched_row_find",0x153c);
                  return 0xffffffff;
                }
                uVar5 = uVar4 + 1 & 0xff;
                local_80[uVar4] = iVar7;
                break;
              }
            }
          }
          puVar6 = puVar6 + 0x1d;
        }
      }
      iVar7 = iVar7 + 1;
      in_stack_0000005c = in_stack_0000005c + 0x7f;
      uVar4 = uVar5;
    } while (iVar7 != in_stack_00000060);
    if ((rdmngr_debug_switch != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
      printf("[RDMNGR_DEBUG]%s()/%d pre_matched rrst_row cnt = %d\n",
             "rdmngr_db_rrst_matched_row_find",0x1543,uVar5);
    }
    uVar3 = 0;
    *in_stack_00000064 = (char)uVar5;
    memcpy(in_stack_00000068,local_80,0x50);
  }
  return uVar3;
}

