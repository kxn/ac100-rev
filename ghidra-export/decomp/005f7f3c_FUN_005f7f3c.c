// func FUN_005f7f3c @ 005f7f3c size=1984

undefined4 FUN_005f7f3c(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint extraout_v1;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint in_t0;
  uint uVar12;
  uint in_t1;
  uint uVar13;
  uint in_t2;
  uint uVar14;
  uint in_t3;
  uint in_t4;
  char *pcVar15;
  char *pcVar16;
  char *pcVar17;
  char *pcVar18;
  undefined4 uVar19;
  char *pcVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  char *pcVar29;
  uint uVar30;
  uint uVar31;
  char *pcVar32;
  char *pcVar33;
  undefined1 auStack_928 [100];
  char acStack_8c4 [132];
  char acStack_840 [2048];
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_30;
  
  memset(acStack_840,0,0x800);
  memset(auStack_928,0,100);
  memset(acStack_8c4,0,0x82);
  uVar4 = param_1 + 0x130;
  puVar6 = auStack_928;
  uVar8 = 100;
  _wserv_sqlite_db_str_tran();
  iVar3 = *(int *)(param_1 + 0x16a);
  if (iVar3 == 1) {
LAB_005f825c:
    uVar4 = param_1 + 0x17a;
    pcVar17 = acStack_8c4;
    uVar9 = 0x82;
    _wserv_sqlite_db_str_tran();
    uVar19 = *(undefined4 *)(param_1 + 0x80);
    if (*(int *)(param_1 + 0x11b) == 0) {
      pcVar20 = "Led off";
    }
    else {
      pcVar20 = "Led on";
    }
    pcVar20 = pcVar20 + 4;
    if (*(int *)(param_1 + 0x11f) == 0) {
      pcVar18 = "Led off";
    }
    else {
      pcVar18 = "Led on";
    }
    pcVar18 = pcVar18 + 4;
    uVar12 = param_1 + 300U & 3;
    uVar26 = param_1 + 0x162U & 3;
    uVar28 = (uint)*(ushort *)(param_1 + 0x123);
    uVar21 = param_1 + 0x166U & 3;
    uVar24 = param_1 + 0x16aU & 3;
    uVar22 = param_1 + 0x16eU & 3;
    uVar27 = (uint)*(ushort *)(param_1 + 0x125);
    uVar23 = param_1 + 0x172U & 3;
    uVar25 = param_1 + 0x176U & 3;
    uVar8 = (uint)*(byte *)(param_1 + 0x1f6);
    uVar13 = param_1 + 0x12fU & 3;
    uVar14 = (*(int *)((param_1 + 300U) - uVar12) << uVar12 * 8 |
             in_t2 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar13 + 1) * 8 |
             *(uint *)((param_1 + 0x12fU) - uVar13) >> (3 - uVar13) * 8;
    uVar12 = param_1 + 0x165U & 3;
    uVar13 = (*(int *)((param_1 + 0x162U) - uVar26) << uVar26 * 8 |
             in_t1 & 0xffffffffU >> (4 - uVar26) * 8) & -1 << (uVar12 + 1) * 8 |
             *(uint *)((param_1 + 0x165U) - uVar12) >> (3 - uVar12) * 8;
    uVar12 = param_1 + 0x169U & 3;
    uVar12 = (*(int *)((param_1 + 0x166U) - uVar21) << uVar21 * 8 |
             in_t0 & 0xffffffffU >> (4 - uVar21) * 8) & -1 << (uVar12 + 1) * 8 |
             *(uint *)((param_1 + 0x169U) - uVar12) >> (3 - uVar12) * 8;
    uVar26 = param_1 + 0x16dU & 3;
    uVar11 = (*(int *)((param_1 + 0x16aU) - uVar24) << uVar24 * 8 |
             param_4 & 0xffffffffU >> (4 - uVar24) * 8) & -1 << (uVar26 + 1) * 8 |
             *(uint *)((param_1 + 0x16dU) - uVar26) >> (3 - uVar26) * 8;
    uVar26 = param_1 + 0x171U & 3;
    uVar10 = (*(int *)((param_1 + 0x16eU) - uVar22) << uVar22 * 8 |
             uVar9 & 0xffffffffU >> (4 - uVar22) * 8) & -1 << (uVar26 + 1) * 8 |
             *(uint *)((param_1 + 0x171U) - uVar26) >> (3 - uVar26) * 8;
    uVar9 = param_1 + 0x175U & 3;
    uVar7 = (*(int *)((param_1 + 0x172U) - uVar23) << uVar23 * 8 |
            (uint)pcVar17 & 0xffffffffU >> (4 - uVar23) * 8) & -1 << (uVar9 + 1) * 8 |
            *(uint *)((param_1 + 0x175U) - uVar9) >> (3 - uVar9) * 8;
    uVar9 = param_1 + 0x179U & 3;
    uVar5 = (*(int *)((param_1 + 0x176U) - uVar25) << uVar25 * 8 |
            uVar4 & 0xffffffffU >> (4 - uVar25) * 8) & -1 << (uVar9 + 1) * 8 |
            *(uint *)((param_1 + 0x179U) - uVar9) >> (3 - uVar9) * 8;
    uVar9 = *(uint *)(param_1 + 0x1ee);
    uVar4 = *(uint *)(param_1 + 0x1f2);
    uVar26 = (uint)*(byte *)(param_1 + 0x1f7);
    if (*(char *)(param_1 + 0x1fa) == '\x01') {
      pcVar17 = "Led on";
    }
    else {
      pcVar17 = "Led off";
    }
    pcVar17 = pcVar17 + 4;
    uVar24 = (uint)*(ushort *)(param_1 + 0x1fc);
    uVar25 = (uint)*(byte *)(param_1 + 0x1fb);
    uVar23 = (uint)*(ushort *)(param_1 + 0x1fe);
    uVar22 = (uint)*(ushort *)(param_1 + 0x200);
    uVar21 = (uint)*(byte *)(param_1 + 0x202);
    if (*(char *)(param_1 + 0x203) == '\x01') {
      pcVar16 = "Led on";
    }
    else {
      pcVar16 = "Led off";
    }
    pcVar16 = pcVar16 + 4;
    if (*(char *)(param_1 + 0x204) == '\x01') {
      pcVar15 = "Led on";
    }
    else {
      pcVar15 = "Led off";
    }
    pcVar15 = pcVar15 + 4;
    pcVar29 = "0.0.0.0";
    pcVar33 = acStack_8c4;
    uVar30 = 0;
    uVar31 = 0;
    pcVar32 = "";
    local_3c = uVar8;
LAB_005f8428:
    snprintf(acStack_840,0x800,
             "INSERT INTO %s (serv_id,enable,auto_bind,default_bind_vlan,default_bind_freq,ssid,ssid_code_type,desc,isolate,ssidbrd,encryption,auth,cipher,radius_ip,radius_port,radius_acct_port,radius_pwd,key_update_intv,key,bw_ctrl_enable,bw_ctrl_mode,up_limit,down_limit,igmp_snooping_enable,igmp_drop_unknown,igmp_2g_rate,igmp_5g_rate,igmp_query_interval,igmp_max_resp_time,igmp_snooping_switch,igmp_query_switch,ssid_id,mlo_switch) VALUES(%d,\'%s\',\'%s\',%d,%d,\'%s\',%d,\'%s\',%d,%d,%d,%d,%d,\'%s\',%d,%d,\'%s\',%d,\'%s\',%d,%d,%d,%d, \'%s\',%d,%d,%d,%d,%d,\'%s\',\'%s\',\'%s\',%d);"
             ,"wserv_tbl",uVar19,pcVar20,pcVar18,uVar28,uVar27,auStack_928,uVar14,param_1 + 0x84,
             uVar13,uVar12,uVar11,uVar10,uVar7,pcVar29,uVar30,uVar31,pcVar32,uVar5,pcVar33,uVar8,
             uVar26,uVar9,uVar4,pcVar17,uVar25,uVar24,uVar23,uVar22,uVar21,pcVar16,pcVar15,
             &DAT_00688af8,*(undefined4 *)(param_1 + 0x128));
  }
  else {
    if (iVar3 < 2 == 0) {
      if (iVar3 == 2) {
        uVar4 = param_1 + 0x1aa;
        pcVar17 = acStack_8c4;
        uVar8 = 0x82;
        _wserv_sqlite_db_str_tran();
        uVar19 = *(undefined4 *)(param_1 + 0x80);
        if (*(int *)(param_1 + 0x11b) == 0) {
          pcVar20 = "Led off";
        }
        else {
          pcVar20 = "Led on";
        }
        pcVar20 = pcVar20 + 4;
        if (*(int *)(param_1 + 0x11f) == 0) {
          pcVar18 = "Led off";
        }
        else {
          pcVar18 = "Led on";
        }
        pcVar18 = pcVar18 + 4;
        pcVar29 = (char *)(param_1 + 0x17a);
        uVar9 = param_1 + 300U & 3;
        uVar12 = param_1 + 0x162U & 3;
        uVar28 = (uint)*(ushort *)(param_1 + 0x123);
        uVar26 = param_1 + 0x166U & 3;
        uVar21 = param_1 + 0x16aU & 3;
        uVar27 = (uint)*(ushort *)(param_1 + 0x125);
        uVar24 = param_1 + 0x16eU & 3;
        uVar22 = param_1 + 0x172U & 3;
        uVar23 = param_1 + 0x1a2U & 3;
        uVar25 = param_1 + 0x1a6U & 3;
        uVar5 = param_1 + 0x176U & 3;
        uVar1 = param_1 + 0x1eeU & 3;
        uVar2 = param_1 + 0x1f2U & 3;
        uVar13 = param_1 + 0x12fU & 3;
        uVar14 = (*(int *)((param_1 + 300U) - uVar9) << uVar9 * 8 |
                 in_t4 & 0xffffffffU >> (4 - uVar9) * 8) & -1 << (uVar13 + 1) * 8 |
                 *(uint *)((param_1 + 0x12fU) - uVar13) >> (3 - uVar13) * 8;
        uVar9 = param_1 + 0x165U & 3;
        uVar13 = (*(int *)((param_1 + 0x162U) - uVar12) << uVar12 * 8 |
                 in_t3 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar9 + 1) * 8 |
                 *(uint *)((param_1 + 0x165U) - uVar9) >> (3 - uVar9) * 8;
        uVar9 = param_1 + 0x169U & 3;
        uVar12 = (*(int *)((param_1 + 0x166U) - uVar26) << uVar26 * 8 |
                 in_t2 & 0xffffffffU >> (4 - uVar26) * 8) & -1 << (uVar9 + 1) * 8 |
                 *(uint *)((param_1 + 0x169U) - uVar9) >> (3 - uVar9) * 8;
        uVar9 = param_1 + 0x16dU & 3;
        uVar11 = (*(int *)((param_1 + 0x16aU) - uVar21) << uVar21 * 8 |
                 in_t1 & 0xffffffffU >> (4 - uVar21) * 8) & -1 << (uVar9 + 1) * 8 |
                 *(uint *)((param_1 + 0x16dU) - uVar9) >> (3 - uVar9) * 8;
        uVar9 = param_1 + 0x171U & 3;
        uVar10 = (*(int *)((param_1 + 0x16eU) - uVar24) << uVar24 * 8 |
                 in_t0 & 0xffffffffU >> (4 - uVar24) * 8) & -1 << (uVar9 + 1) * 8 |
                 *(uint *)((param_1 + 0x171U) - uVar9) >> (3 - uVar9) * 8;
        uVar9 = param_1 + 0x175U & 3;
        uVar7 = (*(int *)((param_1 + 0x172U) - uVar22) << uVar22 * 8 |
                param_4 & 0xffffffffU >> (4 - uVar22) * 8) & -1 << (uVar9 + 1) * 8 |
                *(uint *)((param_1 + 0x175U) - uVar9) >> (3 - uVar9) * 8;
        uVar9 = param_1 + 0x1a5U & 3;
        uVar30 = (*(int *)((param_1 + 0x1a2U) - uVar23) << uVar23 * 8 |
                 uVar8 & 0xffffffffU >> (4 - uVar23) * 8) & -1 << (uVar9 + 1) * 8 |
                 *(uint *)((param_1 + 0x1a5U) - uVar9) >> (3 - uVar9) * 8;
        uVar8 = param_1 + 0x1a9U & 3;
        uVar31 = (*(int *)((param_1 + 0x1a6U) - uVar25) << uVar25 * 8 |
                 (uint)pcVar17 & 0xffffffffU >> (4 - uVar25) * 8) & -1 << (uVar8 + 1) * 8 |
                 *(uint *)((param_1 + 0x1a9U) - uVar8) >> (3 - uVar8) * 8;
        uVar8 = param_1 + 0x179U & 3;
        uVar5 = (*(int *)((param_1 + 0x176U) - uVar5) << uVar5 * 8 |
                uVar4 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar8 + 1) * 8 |
                *(uint *)((param_1 + 0x179U) - uVar8) >> (3 - uVar8) * 8;
        uVar8 = (uint)*(byte *)(param_1 + 0x1f6);
        uVar26 = (uint)*(byte *)(param_1 + 0x1f7);
        uVar4 = param_1 + 0x1f1U & 3;
        uVar9 = (*(int *)((param_1 + 0x1eeU) - uVar1) << uVar1 * 8 |
                extraout_v1 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar4 + 1) * 8 |
                *(uint *)((param_1 + 0x1f1U) - uVar4) >> (3 - uVar4) * 8;
        uVar4 = param_1 + 0x1f5U & 3;
        uVar4 = (*(int *)((param_1 + 0x1f2U) - uVar2) << uVar2 * 8 |
                (uint)*(byte *)(param_1 + 0x126) & 0xffffffffU >> (4 - uVar2) * 8) &
                -1 << (uVar4 + 1) * 8 | *(uint *)((param_1 + 0x1f5U) - uVar4) >> (3 - uVar4) * 8;
        if (*(char *)(param_1 + 0x1fa) == '\x01') {
          pcVar17 = "Led on";
        }
        else {
          pcVar17 = "Led off";
        }
        pcVar17 = pcVar17 + 4;
        uVar25 = (uint)*(byte *)(param_1 + 0x1fb);
        uVar24 = (uint)*(ushort *)(param_1 + 0x1fc);
        uVar23 = (uint)*(ushort *)(param_1 + 0x1fe);
        uVar22 = (uint)*(ushort *)(param_1 + 0x200);
        uVar21 = (uint)*(byte *)(param_1 + 0x202);
        if (*(char *)(param_1 + 0x203) == '\x01') {
          pcVar16 = "Led on";
        }
        else {
          pcVar16 = "Led off";
        }
        pcVar16 = pcVar16 + 4;
        if (*(char *)(param_1 + 0x204) == '\x01') {
          pcVar15 = "Led on";
        }
        else {
          pcVar15 = "Led off";
        }
        pcVar15 = pcVar15 + 4;
        pcVar33 = "0";
        pcVar32 = acStack_8c4;
        local_40 = uVar23;
        local_3c = uVar22;
        local_38 = uVar21;
        local_30 = uVar24;
        goto LAB_005f8428;
      }
      if (iVar3 == 4) goto LAB_005f825c;
    }
    else if (iVar3 == 0) {
      uVar19 = *(undefined4 *)(param_1 + 0x80);
      if (*(int *)(param_1 + 0x11b) == 0) {
        pcVar20 = "Led off";
      }
      else {
        pcVar20 = "Led on";
      }
      pcVar20 = pcVar20 + 4;
      if (*(int *)(param_1 + 0x11f) == 0) {
        pcVar18 = "Led off";
      }
      else {
        pcVar18 = "Led on";
      }
      pcVar18 = pcVar18 + 4;
      uVar9 = param_1 + 300U & 3;
      uVar12 = param_1 + 0x162U & 3;
      uVar28 = (uint)*(ushort *)(param_1 + 0x123);
      uVar26 = param_1 + 0x166U & 3;
      uVar21 = param_1 + 0x1eeU & 3;
      uVar27 = (uint)*(ushort *)(param_1 + 0x125);
      uVar24 = param_1 + 0x1f2U & 3;
      uVar13 = param_1 + 0x12fU & 3;
      uVar14 = (*(int *)((param_1 + 300U) - uVar9) << uVar9 * 8 |
               uVar8 & 0xffffffffU >> (4 - uVar9) * 8) & -1 << (uVar13 + 1) * 8 |
               *(uint *)((param_1 + 0x12fU) - uVar13) >> (3 - uVar13) * 8;
      uVar8 = param_1 + 0x165U & 3;
      uVar13 = (*(int *)((param_1 + 0x162U) - uVar12) << uVar12 * 8 |
               (uint)puVar6 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar8 + 1) * 8 |
               *(uint *)((param_1 + 0x165U) - uVar8) >> (3 - uVar8) * 8;
      uVar8 = param_1 + 0x169U & 3;
      uVar12 = (*(int *)((param_1 + 0x166U) - uVar26) << uVar26 * 8 |
               uVar4 & 0xffffffffU >> (4 - uVar26) * 8) & -1 << (uVar8 + 1) * 8 |
               *(uint *)((param_1 + 0x169U) - uVar8) >> (3 - uVar8) * 8;
      uVar8 = (uint)*(byte *)(param_1 + 0x1f6);
      uVar26 = (uint)*(byte *)(param_1 + 0x1f7);
      uVar4 = param_1 + 0x1f1U & 3;
      uVar9 = (*(int *)((param_1 + 0x1eeU) - uVar21) << uVar21 * 8 |
              (uint)(iVar3 < 2) & 0xffffffffU >> (4 - uVar21) * 8) & -1 << (uVar4 + 1) * 8 |
              *(uint *)((param_1 + 0x1f1U) - uVar4) >> (3 - uVar4) * 8;
      uVar4 = param_1 + 0x1f5U & 3;
      uVar4 = (*(int *)((param_1 + 0x1f2U) - uVar24) << uVar24 * 8 |
              (uint)*(byte *)(param_1 + 0x126) & 0xffffffffU >> (4 - uVar24) * 8) &
              -1 << (uVar4 + 1) * 8 | *(uint *)((param_1 + 0x1f5U) - uVar4) >> (3 - uVar4) * 8;
      if (*(char *)(param_1 + 0x1fa) == '\x01') {
        pcVar17 = "Led on";
      }
      else {
        pcVar17 = "Led off";
      }
      pcVar17 = pcVar17 + 4;
      uVar24 = (uint)*(ushort *)(param_1 + 0x1fc);
      uVar25 = (uint)*(byte *)(param_1 + 0x1fb);
      uVar23 = (uint)*(ushort *)(param_1 + 0x1fe);
      uVar22 = (uint)*(ushort *)(param_1 + 0x200);
      uVar21 = (uint)*(byte *)(param_1 + 0x202);
      if (*(char *)(param_1 + 0x203) == '\x01') {
        pcVar16 = "Led on";
      }
      else {
        pcVar16 = "Led off";
      }
      pcVar16 = pcVar16 + 4;
      if (*(char *)(param_1 + 0x204) == '\x01') {
        pcVar15 = "Led on";
      }
      else {
        pcVar15 = "Led off";
      }
      pcVar15 = pcVar15 + 4;
      uVar10 = 3;
      uVar5 = 0x15180;
      pcVar29 = "0.0.0.0";
      uVar11 = 0;
      uVar7 = 0;
      uVar30 = 0;
      uVar31 = 0;
      pcVar32 = "";
      pcVar33 = "0";
      goto LAB_005f8428;
    }
    if ((g_wserv_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("<wserv>[error]%s(): %d  -> invalid sec_type[%d]\r\n","_wserv_sqlite_do_insert_entry",
             0x45e,*(undefined4 *)(param_1 + 0x16a));
    }
  }
  uVar19 = 0;
  iVar3 = FUN_00407d60(l_wserv_db_handle,acStack_840);
  if (((iVar3 != 0) && (uVar19 = 0xffffffff, g_wserv_error != 0)) &&
     (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("<wserv>[error]%s(): %d  -> uac_sqlite_exec_no_cb() fail, cmd=%s\r\n",
           "_wserv_sqlite_do_insert_entry",0x464,acStack_840);
  }
  return uVar19;
}

