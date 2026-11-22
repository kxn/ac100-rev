// func rrm_pkt_pwr_ctl_update_to_all_ap @ 004ab7b4 size=664

undefined4 rrm_pkt_pwr_ctl_update_to_all_ap(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char cVar5;
  char *__format;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined2 *puVar9;
  int iVar10;
  undefined4 local_480;
  undefined4 local_47c;
  undefined4 local_478;
  undefined4 local_474;
  undefined1 auStack_470 [8];
  char local_468;
  short local_464;
  undefined1 auStack_41c [32];
  short local_3fc;
  short local_3fa;
  undefined1 auStack_308 [64];
  undefined4 local_2c8;
  undefined1 auStack_f0 [192];
  int local_30;
  undefined4 local_2c;
  
  iVar8 = 0;
  piVar6 = &ap_pwr_para;
  memset(auStack_308,0,0x2d8);
  memset(auStack_41c,0,0x114);
  memset(auStack_470,0,0x54);
  local_480 = 0;
  local_47c = 0;
  local_478 = 0;
  local_474 = 0;
  do {
    iVar7 = 0;
    if (*(int *)*piVar6 != 0) {
      for (; iVar7 < *(int *)*piVar6; iVar7 = iVar7 + 1) {
        serv_wtp_address_arg_init(&local_480);
        iVar10 = iVar7 * 0x12;
        iVar2 = apmngr_db_get_addr_by_capacity
                          (*(undefined2 *)(*(int *)(*piVar6 + 0x18) + iVar10),&local_480,1,1,
                           0x15f0000,1,0x1b);
        if (iVar2 == 0) {
          iVar2 = 0;
          local_30 = iVar7 * 0xf;
LAB_004ab908:
          iVar3 = *piVar6;
          do {
            puVar9 = (undefined2 *)(*(int *)(iVar3 + 0x18) + iVar10);
            if ((int)(uint)*(byte *)(puVar9 + 1) <= iVar2) break;
            uVar1 = *(undefined1 *)(*(int *)(iVar3 + 0x1c) + local_30 + iVar2);
            local_2c = rrm_transfer_pwr_to_level
                                 (*(undefined1 *)((int)puVar9 + iVar2 + 3),
                                  *(undefined1 *)((int)puVar9 + iVar2 + 0xc),
                                  *(undefined1 *)((int)puVar9 + iVar2 + 0xf));
            uVar4 = rdmngr_db_generate_rd_id(*puVar9,uVar1);
            iVar3 = apmngr_db_entry_get_by_id
                              (*(undefined2 *)(*(int *)(*piVar6 + 0x18) + iVar10),auStack_308);
            if (iVar3 == 0) {
              iVar3 = rdmngr_db_rd_entry_get(uVar4,auStack_470);
              if ((iVar3 == -1) ||
                 (iVar3 = apdb_get_radio_by_id
                                    (local_2c8,auStack_f0,uVar1,auStack_41c,(int)local_468),
                 iVar3 != 0)) goto LAB_004ab984;
              cVar5 = rdmngr_db_get_pwr_by_level
                                (local_2c,(int)local_3fc,(int)local_3fa,(int)local_464,
                                 (int)local_468);
              iVar3 = _rrm_ctl_packet_send(&local_480,uVar1,iVar8,0xfffffffe,0xfffffffe,(int)cVar5);
              if (iVar3 != -1) {
                iVar2 = iVar2 + 1;
                goto LAB_004ab908;
              }
              if (rrm_err_switch == '\0') {
                iVar2 = iVar2 + 1;
                goto LAB_004ab908;
              }
              __format = "[RRM_ERROR]%s()/%d send packet to AP failed\n";
              uVar4 = 0x2d2;
            }
            else {
LAB_004ab984:
              if (rrm_err_switch == '\0') goto code_r0x004ab98c;
              uVar4 = 0x2cb;
              __format = "[RRM_ERROR]%s()/%d Get rdEntry failed\n";
            }
            iVar2 = iVar2 + 1;
            printf(__format,"rrm_pkt_pwr_ctl_update_to_all_ap",uVar4);
            iVar3 = *piVar6;
          } while( true );
        }
        serv_wtp_address_arg_destroy(&local_480);
      }
    }
    iVar8 = iVar8 + 1;
    piVar6 = piVar6 + 1;
    if (iVar8 == 3) {
      return 0;
    }
  } while( true );
code_r0x004ab98c:
  iVar2 = iVar2 + 1;
  goto LAB_004ab908;
}

