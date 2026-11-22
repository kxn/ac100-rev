// func rrm_pkt_chnl_ctl_update_to_all_ap @ 004ab404 size=944

undefined4 rrm_pkt_chnl_ctl_update_to_all_ap(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  char cVar5;
  int iVar6;
  char *__format;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 local_480;
  undefined4 local_47c;
  undefined4 local_478;
  undefined4 local_474;
  undefined1 auStack_470 [8];
  char local_468;
  char local_467;
  short local_464;
  undefined1 auStack_41c [4];
  int local_418;
  int local_414;
  int local_408;
  short local_3fc;
  undefined1 auStack_308 [64];
  undefined4 local_2c8;
  undefined1 auStack_f0 [192];
  int local_30;
  
  iVar10 = 0;
  piVar8 = &ap_para;
  memset(auStack_470,0,0x54);
  local_480 = 0;
  local_47c = 0;
  local_478 = 0;
  local_474 = 0;
  memset(auStack_308,0,0x2d8);
  memset(auStack_41c,0,0x114);
  do {
    iVar9 = 0;
    if (*(int *)*piVar8 != 0) {
      for (; iVar9 < *(int *)*piVar8; iVar9 = iVar9 + 1) {
        serv_wtp_address_arg_init(&local_480);
        iVar11 = iVar9 * 0x2a;
        iVar2 = apmngr_db_get_addr_by_capacity
                          (*(undefined2 *)(*(int *)(*piVar8 + 0x18) + iVar11),&local_480,1,1,
                           0x15f0000,1,0x1b);
        if (iVar2 == 0) {
          iVar2 = 0;
          local_30 = iVar9 * 0xf;
LAB_004ab554:
          iVar6 = *piVar8;
          do {
            puVar3 = (undefined2 *)(*(int *)(iVar6 + 0x18) + iVar11);
            if ((int)(uint)*(byte *)(puVar3 + 1) <= iVar2) break;
            cVar5 = (char)g_bw_2g;
            if (iVar10 != 0) {
              cVar5 = (char)g_bw_5g;
            }
            iVar7 = (int)cVar5;
            uVar1 = *(undefined1 *)(*(int *)(iVar6 + 0x1c) + local_30 + iVar2);
            uVar4 = rdmngr_db_generate_rd_id(*puVar3,uVar1);
            iVar6 = apmngr_db_entry_get_by_id
                              (*(undefined2 *)(*(int *)(*piVar8 + 0x18) + iVar11),auStack_308);
            if (iVar6 == 0) {
              iVar6 = rdmngr_db_rd_entry_get(uVar4,auStack_470);
              if ((iVar6 == -1) ||
                 (iVar6 = apdb_get_radio_by_id
                                    (local_2c8,auStack_f0,uVar1,auStack_41c,(int)local_468),
                 iVar6 != 0)) goto LAB_004ab5c8;
              cVar5 = rdmngr_db_get_real_max_tx_pwr((int)local_3fc,(int)local_464,(int)local_468);
              if (cVar5 == -1) {
                if (rrm_err_switch == '\0') {
                  iVar2 = iVar2 + 1;
                  goto LAB_004ab554;
                }
                __format = "[RRM_ERROR]%s()/%d _get_real_max_tx_pwr() fail.\n";
                uVar4 = 0x24f;
              }
              else {
                iVar6 = (int)local_467;
                if (local_468 == '\0') {
                  if (((iVar6 - 1U & 0xff) < 2) || (iVar6 == 5)) {
                    if (iVar7 == 0) {
                      iVar7 = 2;
                    }
                    else if (((iVar7 == 1) && (iVar6 = 0xc, local_408 == 0)) &&
                            (iVar6 = 10, local_414 == 0)) {
                      iVar6 = 6;
                    }
                  }
                }
                else if (local_468 == '\x01') {
                  if (iVar6 == 0) {
                    if (iVar7 == 0) {
                      iVar7 = 2;
                    }
                    else if ((((iVar7 == 1) && (iVar6 = 0xd, local_408 == 0)) &&
                             (iVar6 = 0xb, local_414 == 0)) && (iVar6 = 9, local_418 == 0)) {
                      iVar6 = 7;
                    }
                  }
                  else if ((iVar7 == 3) || (iVar7 == 5)) {
                    iVar7 = 3;
                    if (local_408 == 0) {
                      if (local_414 == 0) {
                        iVar7 = 3;
                        iVar6 = 9;
                        if (local_418 == 0) {
                          iVar7 = 1;
                          iVar6 = 7;
                        }
                      }
                      else {
                        iVar6 = 0xb;
                      }
                    }
                    else {
                      iVar6 = 0xd;
                    }
                  }
                }
                iVar6 = _rrm_ctl_packet_send(&local_480,uVar1,iVar10,iVar6,iVar7,(int)cVar5);
                if (iVar6 != -1) {
                  iVar2 = iVar2 + 1;
                  goto LAB_004ab554;
                }
                if (rrm_err_switch == '\0') {
                  iVar2 = iVar2 + 1;
                  goto LAB_004ab554;
                }
                __format = "[RRM_ERROR]%s()/%d send packet to AP failed\n";
                uVar4 = 0x2a0;
              }
            }
            else {
LAB_004ab5c8:
              if (rrm_err_switch == '\0') goto code_r0x004ab5d4;
              uVar4 = 0x248;
              __format = "[RRM_ERROR]%s()/%d Get rdEntry failed\n";
            }
            iVar2 = iVar2 + 1;
            printf(__format,"rrm_pkt_chnl_ctl_update_to_all_ap",uVar4);
            iVar6 = *piVar8;
          } while( true );
        }
        serv_wtp_address_arg_destroy(&local_480);
      }
    }
    iVar10 = iVar10 + 1;
    piVar8 = piVar8 + 1;
    if (iVar10 == 3) {
      return 0;
    }
  } while( true );
code_r0x004ab5d4:
  iVar2 = iVar2 + 1;
  goto LAB_004ab554;
}

