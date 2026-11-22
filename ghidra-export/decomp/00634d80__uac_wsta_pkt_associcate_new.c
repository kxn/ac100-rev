// func _uac_wsta_pkt_associcate_new @ 00634d80 size=3280

undefined4
_uac_wsta_pkt_associcate_new
          (undefined1 *param_1,undefined4 param_2,byte *param_3,undefined4 param_4)

{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined1 uVar9;
  uint uVar7;
  byte *pbVar8;
  char *pcVar10;
  char cVar12;
  int iVar11;
  undefined4 uVar13;
  int iVar14;
  uint uVar15;
  undefined1 *__src;
  undefined1 *__dest;
  int iVar16;
  uint uVar17;
  uint local_630;
  byte *local_62c;
  uint local_628;
  int *local_624;
  undefined4 *local_620;
  byte *local_61c;
  undefined4 local_618;
  int *local_614;
  undefined4 local_610;
  byte *local_60c;
  undefined4 local_608;
  undefined2 local_5f8 [2];
  undefined4 local_5f4;
  undefined4 local_5f0;
  int local_5ec;
  undefined4 local_5e8;
  undefined4 local_5e4;
  undefined4 local_5e0;
  undefined4 local_5dc;
  undefined4 local_5d8;
  undefined4 local_5d4;
  byte local_5d0 [20];
  int local_5bc [5];
  byte local_5a8;
  undefined1 local_5a7;
  uint local_5a4;
  undefined1 auStack_5a0 [3];
  undefined1 local_59d;
  byte local_59c;
  undefined1 auStack_59b [6];
  undefined1 auStack_595 [21];
  uint local_580;
  undefined4 local_57c;
  undefined4 local_578;
  uint local_574;
  byte local_570 [41];
  undefined1 local_547;
  undefined1 auStack_546 [6];
  int local_540;
  undefined1 local_53c [8];
  undefined1 auStack_534 [2];
  undefined1 auStack_532 [42];
  undefined1 auStack_508 [283];
  int local_3ed;
  undefined1 auStack_300 [16];
  ushort local_2f0;
  int aiStack_2b2 [135];
  byte local_95;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  uint local_84;
  
  local_5bc[0] = 0;
  local_5bc[1] = 0;
  local_5bc[2] = 0;
  local_5bc[3] = 0;
  local_5bc[4] = 0;
  local_5d0[0] = 0;
  local_5d0[1] = 0;
  local_5d0[2] = 0;
  local_5d0[3] = 0;
  local_5d0[4] = 0;
  local_5d0[5] = 0;
  local_5d0[6] = 0;
  local_5d0[7] = 0;
  local_5d0[8] = 0;
  local_5d0[9] = 0;
  local_5d0[10] = 0;
  local_5d0[0xb] = 0;
  local_5d0[0xc] = 0;
  local_5d0[0xd] = 0;
  local_5d0[0xe] = 0;
  local_5d0[0xf] = 0;
  local_5d0[0x10] = 0;
  local_5d0[0x11] = 0;
  local_5d0[0x12] = 0;
  local_5d0[0x13] = 0;
  local_5ec = 0;
  local_5e8 = 0;
  memset(&local_580,0,0x38);
  local_5f4 = 0;
  local_5f0 = 0;
  iVar4 = apmngr_db_entry_get_by_mac(param_3,auStack_300);
  if (iVar4 != 0) {
    iVar4 = 0x25;
    if ((g_wsta_warning == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0)) goto LAB_00634e24;
    pcVar10 = "<wsta>[warning]%s(): %d  -> apmngr_db_entry_get_by_mac() fail.\r\n";
    uVar13 = 0x21b;
    goto LAB_00634fac;
  }
  iVar4 = cw_sta_assoc_req_subelement_get(param_1,1);
  if ((iVar4 == 0) || ((local_95 & 2) == 0)) {
    local_630 = 0;
    iVar4 = _uac_wsta_do_check(local_2f0,*param_1,param_1[1],param_1 + 2);
    bVar2 = false;
    if (iVar4 != 0) goto LAB_00634e24;
LAB_00635004:
    if (bVar2) {
      if (g_wsta_debug == 0) {
        cVar12 = param_1[0xc];
      }
      else {
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          cVar12 = param_1[0xc];
        }
        else {
          printf("<wsta>[debug]%s(): %d  -> mlo sta assoc\r\n","_uac_wsta_pkt_associcate_new",600);
          cVar12 = param_1[0xc];
        }
      }
      iVar5 = uac_wstation_mlo_peer_assoc(&local_580,cVar12 != '\0',&local_5ec);
      if ((iVar5 != 0) && (iVar5 != 2)) goto LAB_00635044;
      bVar2 = false;
      iVar5 = 0;
      while (iVar5 < (int)(uint)local_570[2]) {
        iVar11 = iVar5 * 0xc;
        iVar5 = iVar5 + 1;
        iVar11 = memcmp(&local_574,local_570 + iVar11 + 6,6);
        if (iVar11 == 0) {
          bVar2 = true;
        }
      }
      if (bVar2) {
        iVar5 = 0;
LAB_0063535c:
        for (uVar6 = 0; uVar6 < 0x28; uVar6 = uVar6 + 1) {
          *(byte *)((int)&local_630 + uVar6) = local_570[uVar6];
        }
        iVar11 = wsta_db_set_mlo_mac_entry(local_580,local_57c,local_578,local_574);
        if (((iVar11 == -1) && (iVar4 = 0x25, g_wsta_error != 0)) &&
           (iVar11 = is_target_debug_ap(), iVar11 != 0)) {
          printf("<wsta>[error]%s(): %d  -> set mlo hash error\r\n","_uac_wsta_pkt_associcate_new",
                 0x275);
        }
      }
      else {
        local_5f0 = 1;
        local_630 = *(uint *)(param_1 + 8);
        local_5f4 = 0;
        local_628 = (uint)(param_1[0xc] != '\0');
        local_62c = (byte *)0x0;
        local_624 = &local_5ec;
        local_620 = &local_5f4;
        iVar5 = uac_wstation_assoc(local_2f0,local_578._2_1_,local_578 & 0xff,&local_574);
        if ((iVar5 == 0) || (iVar5 == 2)) goto LAB_0063535c;
      }
      uVar6 = iVar5 - 3;
      if (g_wsta_debug != 0) {
        iVar11 = is_target_debug_ap();
        if (iVar11 == 0) {
          uVar6 = iVar5 - 3;
        }
        else {
          printf("<wsta>[debug]%s(): %d  -> assoc fin\r\n","_uac_wsta_pkt_associcate_new",0x279);
          uVar6 = iVar5 - 3;
        }
      }
    }
    else {
      local_630 = *(uint *)(param_1 + 8);
      local_5f4 = 0;
      local_628 = (uint)(param_1[0xc] != '\0');
      local_62c = (byte *)0x0;
      local_624 = &local_5ec;
      local_620 = &local_5f4;
      iVar5 = uac_wstation_assoc(local_2f0,*param_1,param_1[1],param_1 + 2);
LAB_00635044:
      uVar6 = iVar5 - 3;
    }
    if (uVar6 < 2) {
      local_630 = (uint)param_3[1];
      local_62c = (byte *)(uint)param_3[2];
      local_628 = (uint)param_3[3];
      local_624 = (int *)(uint)param_3[4];
      local_620 = (undefined4 *)(uint)param_3[5];
      snprintf((char *)local_5bc,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*param_3);
      local_630 = (uint)(byte)param_1[3];
      local_62c = (byte *)(uint)(byte)param_1[4];
      local_628 = (uint)(byte)param_1[5];
      local_624 = (int *)(uint)(byte)param_1[6];
      local_620 = (undefined4 *)(uint)(byte)param_1[7];
      snprintf((char *)local_5d0,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)(byte)param_1[2]);
      memset(local_570 + 0x28,0,0x40);
      local_62c = local_570 + 0x28;
      local_624 = (int *)0x6bb290;
      local_628 = 0x40;
      local_630 = local_84;
      FUN_00408190(local_94,local_90,local_8c,local_88);
      if (iVar5 == 3) {
        uVar13 = rdmngr_db_generate_rd_id(local_2f0,*param_1);
        uVar13 = rdmngr_db_get_rd_freq_band(uVar13);
        pbVar8 = (byte *)apdb_get_radio_freq_name_by_freq(uVar13);
        local_624 = aiStack_2b2;
        local_62c = (byte *)0x6bb290;
        if (pbVar8 != (byte *)0x0) {
          local_62c = pbVar8;
        }
        local_614 = local_5bc;
        local_630 = 1;
        local_628 = 1;
        local_61c = local_570 + 0x28;
        local_620 = (undefined4 *)0x1;
        local_618 = 1;
        local_610 = 1;
        local_60c = local_5d0;
        local_608 = 0;
        loggerk_reg(0x5b,0x3a9c,3,*param_1);
      }
      else {
        local_618 = 0;
        local_624 = local_5bc;
        local_630 = 1;
        local_62c = local_570 + 0x28;
        local_628 = 1;
        local_620 = (undefined4 *)0x1;
        local_61c = local_5d0;
        loggerk_reg(0x5b,0x3a9d,1,aiStack_2b2);
      }
      iVar4 = 0x11;
      if ((g_wsta_warning != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
        pcVar10 = "<wsta>[warning]%s(): %d  -> uac_wstation_assoc() fail.\r\n";
        uVar13 = 0x29a;
LAB_00634fac:
        printf(pcVar10,"_uac_wsta_pkt_associcate_new",uVar13);
      }
      goto LAB_00634e24;
    }
    if (iVar5 == -1) {
      iVar4 = 0x25;
      if ((g_wsta_warning != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
        pcVar10 = "<wsta>[warning]%s(): %d  -> uac_wstation_assoc() fail.\r\n";
        uVar13 = 0x29f;
        goto LAB_00634fac;
      }
      goto LAB_00634e24;
    }
    if (iVar4 != 0) goto LAB_00634e24;
    uVar13 = 0;
  }
  else {
    memset(&local_580,0,0x38);
    local_580 = (uint)local_2f0;
    if (g_wsta_debug != 0) {
      iVar5 = is_target_debug_ap();
      if (iVar5 == 0) {
        local_580 = (uint)local_2f0;
      }
      else {
        printf("<wsta>[debug]%s(): %d  -> get mlo val num:%d\r\n","_uac_wsta_pkt_associcate_new",
               0x225,(uint)*(byte *)(iVar4 + 10));
        local_580 = (uint)local_2f0;
      }
    }
    if (*(byte *)(iVar4 + 10) < 4) {
      memcpy(&local_57c,param_1 + 2,6);
      memcpy(&local_574,(void *)(iVar4 + 4),6);
      if (g_wsta_debug == 0) {
        uVar9 = *param_1;
      }
      else {
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          uVar9 = *param_1;
        }
        else {
          local_630 = local_574 >> 0x10 & 0xff;
          local_62c = (byte *)(local_574 >> 8 & 0xff);
          local_628 = local_574 & 0xff;
          local_624 = (int *)(uint)local_570[0];
          local_620 = (undefined4 *)(uint)local_570[1];
          printf("<wsta>[debug]%s(): %d  -> mld mac: %02x:%02x:%02x:%02x:%02x:%02x \r\n\r\n",
                 "_uac_wsta_pkt_associcate_new",0x231,local_574 >> 0x18);
          uVar9 = *param_1;
        }
      }
      pbVar8 = local_570 + 6;
      iVar5 = 0;
      local_578 = CONCAT31(CONCAT21(local_578._0_2_,uVar9),param_1[1]);
      local_570[2] = *(byte *)(iVar4 + 10);
      do {
        bVar1 = *(byte *)(iVar4 + 10);
LAB_006350f4:
        if ((int)(uint)bVar1 <= iVar5) goto LAB_006353cc;
        iVar16 = iVar5 * 0xc;
        pbVar8[-2] = *(byte *)(*(int *)(iVar4 + 0xc) + iVar16);
        pbVar8[-1] = *(byte *)(*(int *)(iVar4 + 0xc) + iVar16 + 1);
        iVar14 = *(int *)(iVar4 + 0xc) + iVar16;
        iVar11 = memcmp(&local_57c,(void *)(iVar14 + 2),6);
        if (iVar11 == 0) {
          uVar13 = *(undefined4 *)(param_1 + 8);
        }
        else {
          uVar13 = *(undefined4 *)(iVar14 + 8);
        }
        *(undefined4 *)(pbVar8 + 6) = uVar13;
        memcpy(pbVar8,(void *)(*(int *)(iVar4 + 0xc) + iVar16 + 2),6);
        if ((g_wsta_debug != 0) && (iVar11 = is_target_debug_ap(), iVar11 != 0))
        goto code_r0x006352f8;
        iVar5 = iVar5 + 1;
        pbVar8 = pbVar8 + 0xc;
      } while( true );
    }
    iVar4 = 0x25;
    if ((g_wsta_warning != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      pcVar10 = "<wsta>[warning]%s(): %d  -> mlo link num is unexpected.\r\n";
      uVar13 = 0x22a;
      goto LAB_00634fac;
    }
LAB_00634e24:
    uVar13 = 0x15;
  }
  _uac_wsta_pkt_set_result_code(param_4,uVar13);
  local_5e4 = 0;
  local_5e0 = 0;
  local_5dc = 0;
  local_5d8 = 0;
  local_5d4 = 0;
  memset(local_570 + 0x28,0,0x20);
  local_570[0x28] = *param_1;
  local_5f8[0] = 0;
  local_547 = param_1[1];
  memcpy(auStack_546,param_1 + 2,6);
  local_53c[0] = param_1[0xc];
  local_540 = iVar4;
  FUN_0051ad88(auStack_534);
  if (local_5ec == 0) {
LAB_00634eb4:
    iVar4 = cw_sta_assoc_req_subelement_get(param_1);
    if ((iVar4 == 0) ||
       (iVar4 = cw_sta_assoc_rslt_subelement_add(local_570 + 0x28,1,iVar4), iVar4 == 0)) {
      iVar4 = cw_sta_assoc_req_subelement_get(param_1,1);
      if ((iVar4 == 0) ||
         (iVar4 = cw_sta_assoc_rslt_subelement_add(local_570 + 0x28,2,0), iVar4 == 0)) {
        FUN_0051ad88(&local_5dc);
        local_5e4 = 0x12345678;
        local_5e0 = CONCAT22(0x8b,local_5e0._2_2_);
        local_630 = 0x8b;
        local_62c = local_570 + 0x28;
        iVar4 = cw_service_msg_add(param_4,0x25,&local_5e4,1);
        if (iVar4 == 0) {
          cw_sta_assoc_rslt_sub_ele_free(local_570 + 0x28);
          return 0;
        }
        if ((g_wsta_error == 0) || (iVar4 = is_target_debug_ap(local_570 + 0x28), iVar4 == 0))
        goto LAB_0063526c;
        pcVar10 = "<wsta>[error]%s(): %d  -> set wsta assoc rslt vendor payload fail!\r\n";
        uVar13 = 0x195;
      }
      else {
        if ((g_wsta_error == 0) || (iVar4 = is_target_debug_ap(local_570 + 0x28), iVar4 == 0))
        goto LAB_0063526c;
        pcVar10 = "<wsta>[error]%s(): %d  -> add wsta assoc rslt for sub mlo fail!\r\n";
        uVar13 = 0x188;
      }
    }
    else {
      if ((g_wsta_error == 0) || (iVar4 = is_target_debug_ap(local_570 + 0x28), iVar4 == 0))
      goto LAB_0063526c;
      pcVar10 = "<wsta>[error]%s(): %d  -> add wsta assoc rslt for sub backfill fail!\r\n";
      uVar13 = 0x180;
    }
  }
  else {
    local_5f8[0] = local_5e8._0_2_;
    iVar4 = cw_sta_assoc_rslt_subelement_add(local_570 + 0x28,0,local_5f8);
    if (iVar4 == 0) goto LAB_00634eb4;
    if ((g_wsta_error == 0) || (iVar4 = is_target_debug_ap(local_570 + 0x28,0), iVar4 == 0))
    goto LAB_0063526c;
    pcVar10 = "<wsta>[error]%s(): %d  -> add wsta assoc rslt for sub vlan fail!\r\n";
    uVar13 = 0x178;
  }
  printf(pcVar10,"_uac_wsta_pkt_assemble_assoc_response_elem_new",uVar13);
LAB_0063526c:
  cw_sta_assoc_rslt_sub_ele_free(local_570 + 0x28);
  if ((g_wsta_warning != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
    printf("<wsta>[warning]%s(): %d  -> _uac_wsta_pkt_assemble_assoc_response_elem() fail.\r\n",
           "_uac_wsta_pkt_associcate_new",0x2b8);
  }
  return 0xffffffff;
LAB_006353cc:
  memcpy(local_570 + 0x28,&local_580,0x38);
  bVar3 = local_570[2];
  uVar6 = local_580;
  bVar1 = local_578._2_1_;
  uVar15 = (uint)local_578._2_1_;
  uVar9 = (undefined1)local_578;
  pbVar8 = (byte *)(local_578 & 0xff);
  uVar17 = (uint)local_570[2];
  memset(auStack_508,0,0x205);
  if ((g_wsta_debug != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
    printf("<wsta>[debug]%s(): %d  -> do check new\r\n","_uac_wsta_do_check_new",0x9c);
  }
  iVar4 = 0;
  if (DAT_007cca9c == 0) goto LAB_0063542c;
  if ((uVar15 == 0) || (uVar7 = rdmngr_profile_get_max_rd_per_ap(), uVar7 < uVar15)) {
    iVar4 = 0x25;
    if ((g_wsta_error != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      local_630 = uVar15;
      local_62c = pbVar8;
      printf("<wsta>[error]%s(): %d  -> invalid ap id[%d],radio_id[%d],wlan id[%d]!\r\n",
             "_uac_wsta_do_check_new",0xa3,uVar6);
    }
    goto LAB_0063542c;
  }
  __dest = auStack_595;
  memset(&local_5a8,0,0x28);
  local_5a4 = uVar6;
  local_5a8 = bVar1;
  local_5a7 = uVar9;
  __src = auStack_532;
  local_59d = 1;
  local_59c = bVar3;
  memcpy(auStack_59b,local_53c,6);
  for (iVar4 = 0; iVar4 < (int)uVar17; iVar4 = iVar4 + 1) {
    memcpy(__dest,__src,6);
    __src = __src + 0xc;
    __dest = __dest + 6;
  }
  iVar4 = 0x25;
  uVar13 = rdmngr_db_generate_rd_id(local_5a4,local_5a8);
  iVar5 = wserv_db_rd_get_wserv_id(uVar13,local_5a7);
  if ((((iVar5 == -1) || (iVar5 = wserv_db_get_entry_by_id(iVar5,auStack_508), iVar5 != 0)) ||
      (local_3ed == 0)) ||
     (iVar5 = uac_wservice_get_vlan(local_5a4,local_5a8,local_5a7,auStack_5a0), iVar5 != 0))
  goto LAB_0063542c;
  iVar5 = FUN_004081b0(&l_wsta_assoc_check_reg);
  do {
    if (iVar5 == 0) {
      iVar4 = 0;
LAB_006359c8:
      if ((g_wsta_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
        printf("<wsta>[debug]%s(): %d  -> rslt:%d\r\n","_uac_wsta_do_check_new",0xcf,iVar4);
      }
LAB_0063542c:
      bVar2 = true;
      if (iVar4 == 0) goto LAB_00635004;
      goto LAB_00634e24;
    }
    if (*(int **)(iVar5 + 0x34) == (int *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = **(int **)(iVar5 + 0x34);
      if (iVar4 == 0) {
        iVar4 = 0;
      }
    }
    iVar4 = (**(code **)(iVar5 + 0x30))(&local_5a8,iVar4);
    if (iVar4 != 0) {
      if ((g_wsta_warning != 0) && (iVar11 = is_target_debug_ap(), iVar11 != 0)) {
        printf("<wsta>[warning]%s(): %d  -> do_check() fail, reg[%s].\r\n","_uac_wsta_do_check_new",
               0xca,iVar5 + 0xc);
      }
      goto LAB_006359c8;
    }
    iVar5 = FUN_00408680(iVar5);
  } while( true );
code_r0x006352f8:
  local_630 = (uint)*pbVar8;
  iVar11 = iVar5 + 1;
  local_62c = (byte *)(uint)pbVar8[1];
  iVar5 = iVar5 + 1;
  local_628 = (uint)pbVar8[2];
  local_624 = (int *)(uint)pbVar8[3];
  local_620 = (undefined4 *)(uint)pbVar8[4];
  local_61c = (byte *)(uint)pbVar8[5];
  pbVar8 = pbVar8 + 0xc;
  printf("<wsta>[debug]%s(): %d  -> peer%d mac: %02x:%02x:%02x:%02x:%02x:%02x \r\n\r\n",
         "_uac_wsta_pkt_associcate_new",0x244,iVar11);
  bVar1 = *(byte *)(iVar4 + 10);
  goto LAB_006350f4;
}

