// func _ac_cmcc_worker_thread @ 00438734 size=3416

undefined4 _ac_cmcc_worker_thread(int *param_1)

{
  bool bVar1;
  uint uVar2;
  byte bVar3;
  uint *__src;
  uint *__s;
  int iVar4;
  undefined4 *puVar5;
  time_t tVar6;
  __pid_t _Var7;
  __pid_t _Var8;
  uint uVar9;
  ssize_t sVar10;
  ushort uVar11;
  uint uVar12;
  short sVar13;
  byte bVar14;
  char *pcVar15;
  undefined2 uVar17;
  undefined1 *puVar16;
  char *pcVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  int iVar21;
  uint *puVar22;
  uint *puVar23;
  int iVar24;
  undefined8 uVar25;
  int local_130;
  undefined4 local_12c;
  uint local_128;
  uint local_124;
  undefined4 local_120;
  undefined4 local_11c;
  uint local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined2 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  uint local_f8;
  undefined2 local_f4;
  undefined4 local_f0;
  uint local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  int local_dc;
  sockaddr sStack_d8;
  uint *local_bc;
  int local_b8;
  int local_b4;
  undefined1 auStack_b0 [46];
  ushort local_82;
  uint local_48;
  undefined2 local_44;
  int local_30;
  
  local_12c = 0;
  if (param_1 != (int *)0x0) {
    iVar21 = *param_1;
    FUN_00407df0();
    local_30 = _cmcc_threads + iVar21 * 8;
    __s = (uint *)FUN_00408450(0x640,0x778);
    if (__s != (uint *)0x0) {
LAB_004387a8:
      memset(&local_dc,0,0x2c);
      puVar5 = &local_12c;
      iVar21 = FUN_00408250(*(undefined4 *)(local_30 + 4),&local_dc,0x2c,0xffffffff,puVar5);
      __src = local_bc;
      if (iVar21 != -1) goto code_r0x004387e0;
      if ((wportal_debug_switch != 0) && (iVar21 = is_target_debug_ap(), iVar21 != 0)) {
        pcVar15 = "[WPORTAL_DBG]%s()/%d Get msgq error\n";
        uVar19 = 0x785;
        pcVar18 = "_ac_cmcc_worker_thread";
        goto LAB_00438864;
      }
      goto LAB_00438820;
    }
  }
  return 0;
code_r0x004387e0:
  if (local_b8 != 1) goto LAB_004387a8;
  uVar12 = *local_bc;
  if (uVar12 >> 0x18 != 1) {
    if ((wportal_debug_switch == 0) || (iVar21 = is_target_debug_ap(), iVar21 == 0))
    goto LAB_00438820;
    uVar12 = (uint)*(byte *)__src;
    pcVar15 = "[WPORTAL_DBG]%s()/%d Cmcc packet version error: %x\n\n";
    uVar19 = 0x1b1;
    pcVar18 = "_ac_cmcc_pkt_check";
    goto LAB_004388b8;
  }
  uVar9 = (uVar12 << 8) >> 0x18;
  uVar2 = (uVar12 << 0x10) >> 0x18;
  if (10 < uVar9) {
    if ((wportal_debug_switch == 0) || (iVar21 = is_target_debug_ap(), iVar21 == 0))
    goto LAB_00438820;
    pcVar15 = "[WPORTAL_DBG]%s()/%d Cmcc packet type error: %x\n\n";
    pcVar18 = "_ac_cmcc_pkt_check";
    uVar19 = 0x1b7;
    goto LAB_004388b4;
  }
  if (1 < uVar2) {
    if ((wportal_debug_switch == 0) || (iVar21 = is_target_debug_ap(), iVar21 == 0))
    goto LAB_00438820;
    uVar12 = (uint)*(byte *)((int)__src + 2);
    pcVar15 = "[WPORTAL_DBG]%s()/%d Cmcc packet chap pap type error: %x\n\n";
    uVar19 = 0x1bd;
    pcVar18 = "_ac_cmcc_pkt_check";
    goto LAB_004388b8;
  }
  if ((uVar12 & 0xff) != 0) {
    if ((wportal_debug_switch == 0) || (iVar21 = is_target_debug_ap(), iVar21 == 0))
    goto LAB_00438820;
    uVar12 = (uint)(byte)*__src;
    pcVar15 = "[WPORTAL_DBG]%s()/%d Cmcc packet reserve error: %x\n\n";
    uVar19 = 0x1c3;
    pcVar18 = "_ac_cmcc_pkt_check";
    goto LAB_004388b8;
  }
  if (uVar2 == 1) {
    sVar13 = *(short *)((int)local_bc + 6);
LAB_004389c0:
    if (sVar13 != 0) {
      if ((wportal_debug_switch == 0) || (iVar21 = is_target_debug_ap(), iVar21 == 0))
      goto LAB_00438820;
      uVar12 = (uint)*(ushort *)((int)__src + 6);
      pcVar15 = "[WPORTAL_DBG]%s()/%d IN cmcc packet pap type, reqid must be 0: %x\n\n";
      uVar19 = 0x1cd;
      pcVar18 = "_ac_cmcc_pkt_check";
      goto LAB_004388b8;
    }
    uVar12 = local_bc[2];
  }
  else {
    if (uVar9 == 1) {
      sVar13 = *(short *)((int)local_bc + 6);
      goto LAB_004389c0;
    }
    if (uVar9 == 6) {
      sVar13 = *(short *)((int)local_bc + 6);
      goto LAB_004389c0;
    }
    uVar12 = local_bc[2];
  }
  if (uVar12 == 0) {
    if ((wportal_debug_switch == 0) || (iVar21 = is_target_debug_ap(), iVar21 == 0))
    goto LAB_00438820;
    pcVar15 = "[WPORTAL_DBG]%s()/%d Cmcc packet user ip empty\n\n";
    uVar19 = 0x1d4;
    pcVar18 = "_ac_cmcc_pkt_check";
    goto LAB_00438864;
  }
  if (*(short *)(local_bc + 3) != 0) {
    if ((wportal_debug_switch == 0) || (iVar21 = is_target_debug_ap(), iVar21 == 0))
    goto LAB_00438820;
    uVar12 = (uint)*(ushort *)(__src + 3);
    pcVar15 = "[WPORTAL_DBG]%s()/%d Cmcc packet user port is not empty: %x\n\n";
    uVar19 = 0x1da;
    pcVar18 = "_ac_cmcc_pkt_check";
    goto LAB_004388b8;
  }
  switch(uVar9) {
  case 1:
    if ((wportal_debug_switch != 0) && (iVar21 = is_target_debug_ap(), iVar21 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d Receive REQ_CHALLENGE packet\n","_ac_cmcc_pkt_manage",0x734);
    }
    iVar21 = local_b4;
    local_128 = 0;
    local_124 = 0;
    local_120 = 0;
    local_11c = 0;
    tVar6 = time((time_t *)0x0);
    _Var7 = getppid();
    _Var8 = getpid();
    srand(tVar6 + _Var7 + _Var8);
    puVar23 = &local_128;
    do {
      local_130 = rand();
      puVar22 = puVar23 + 1;
      memcpy(puVar23,&local_130,4);
      puVar23 = puVar22;
    } while (puVar22 != &local_118);
    uVar12 = time((time_t *)0x0);
    srand(uVar12);
    uVar12 = rand();
    memset(__s,0,0x640);
    memcpy(__s,__src,0x10);
    bVar1 = wportal_debug_switch == 0;
    *(short *)((int)__s + 6) = (short)uVar12;
    if (bVar1) {
      uVar17 = *(undefined2 *)(__src + 1);
    }
    else {
      iVar24 = is_target_debug_ap();
      if (iVar24 == 0) {
        uVar17 = *(undefined2 *)(__src + 1);
      }
      else {
        printf("[WPORTAL_DBG]%s()/%d Add serial no: %d\n\n","_ac_cmcc_pkt_challenge_manage",0x208,
               (uint)*(ushort *)(__src + 1));
        uVar17 = *(undefined2 *)(__src + 1);
      }
    }
    iVar24 = wportal_db_cmcc_add_serialno(uVar17,&local_128,uVar12 & 0xffff);
    if (iVar24 != 0) {
      if (wportal_debug_switch == 0) {
        uVar11 = *(ushort *)((int)__s + 0xe);
      }
      else {
        iVar21 = is_target_debug_ap();
        if (iVar21 == 0) {
          uVar11 = *(ushort *)((int)__s + 0xe);
        }
        else {
          printf("[WPORTAL_DBG]%s()/%d Add to serialno tree error\n","_ac_cmcc_pkt_challenge_manage"
                 ,0x20c);
          uVar11 = *(ushort *)((int)__s + 0xe);
        }
      }
      uVar19 = 2;
      *(ushort *)((int)__s + 0xe) = uVar11 & 0xff00;
      uVar20 = 3;
      goto LAB_00438e78;
    }
    puVar16 = (undefined1 *)((int)__s + iVar21);
    *__s = *__s & 0xff00ffff | 0x20000;
    *(undefined2 *)((int)__s + 0xe) = 1;
    *puVar16 = 3;
    puVar16[1] = 0x12;
    memcpy(puVar16 + 2,&local_128,0x10);
    if (local_dc == 1) {
      sVar10 = sendto(cmcc_sockfd,__s,0x22,0,&sStack_d8,0x10);
      if (((-1 < sVar10) || (wportal_debug_switch == 0)) ||
         (iVar21 = is_target_debug_ap(), iVar21 == 0)) goto LAB_00438820;
      pcVar15 = "[WPORTAL_DBG]%s()/%d Send error\n";
      pcVar18 = "_ac_cmcc_pkt_challenge_manage";
      uVar19 = 0x227;
    }
    else {
      if ((((local_dc != 2) ||
           (sVar10 = sendto(cmcc_sockfd_v6,__s,0x22,0,&sStack_d8,0x1c), -1 < sVar10)) ||
          (wportal_debug_switch == 0)) || (iVar21 = is_target_debug_ap(), iVar21 == 0))
      goto LAB_00438820;
      pcVar15 = "[WPORTAL_DBG]%s()/%d Send error\n";
      pcVar18 = "_ac_cmcc_pkt_challenge_manage";
      uVar19 = 0x230;
    }
    break;
  case 2:
  case 4:
  case 6:
  case 8:
  default:
    if ((wportal_debug_switch != 0) && (iVar21 = is_target_debug_ap(), iVar21 != 0)) {
      pcVar15 = "[WPORTAL_DBG]%s()/%d Not manage packet: %x\n\n";
      pcVar18 = "_ac_cmcc_pkt_manage";
      uVar19 = 0x74d;
LAB_004388b4:
      uVar12 = (uint)*(byte *)((int)__src + 1);
LAB_004388b8:
      printf(pcVar15,pcVar18,uVar19,uVar12,puVar5);
    }
    goto LAB_00438820;
  case 3:
    if ((wportal_debug_switch != 0) && (iVar21 = is_target_debug_ap(1,local_b4), iVar21 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d Receive REQ_AUTH packet\n","_ac_cmcc_pkt_manage",0x739);
    }
    _ac_cmcc_pkt_auth_manage(__src,local_b4,&local_dc,__s);
    goto LAB_00438820;
  case 5:
    if ((wportal_debug_switch != 0) && (iVar21 = is_target_debug_ap(), iVar21 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d Receive REQ_LOGOUT packet\n","_ac_cmcc_pkt_manage",0x73e);
    }
    local_104 = 0;
    local_100 = 0;
    local_fc = 0;
    puVar23 = __src + 4;
    local_f8 = 0;
    iVar21 = local_b4 + -0x10;
    local_f4 = 0;
    local_128 = 0;
    local_124 = local_124 & 0xffff;
    bVar3 = *(byte *)((int)__src + 0xf);
    memset(__s,0,0x640);
    memcpy(__s,__src,0x10);
    if ((wportal_debug_switch != 0) && (iVar24 = is_target_debug_ap(), iVar24 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d Get attribute: %d\n\n","_ac_cmcc_pkt_logout_manage",0x690,
             (uint)bVar3);
    }
    bVar1 = false;
    iVar24 = 0;
    for (; (iVar24 < (int)(uint)bVar3 && (0 < iVar21));
        iVar21 = iVar21 - (uint)*(byte *)((int)puVar23 + 1)) {
      if (wportal_debug_switch == 0) {
        bVar14 = *(byte *)puVar23;
      }
      else {
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          bVar14 = *(byte *)puVar23;
        }
        else {
          puVar5 = (undefined4 *)(uint)*(byte *)((int)puVar23 + 1);
          printf("[WPORTAL_DBG]%s()/%d Get attr type: %x, len: %d\n\n","_ac_cmcc_pkt_logout_manage",
                 0x693,(uint)*(byte *)puVar23,puVar5);
          bVar14 = *(byte *)puVar23;
        }
      }
      if (bVar14 == 0x55) {
        if (*(byte *)((int)puVar23 + 1) == 0xe) {
          bVar1 = true;
          strncpy((char *)&local_104,(char *)((int)puVar23 + 2),0xc);
          local_f8 = local_f8 & 0xffffff;
          FUN_004360d4(&local_128,&local_104);
          uVar12 = (uint)*(byte *)((int)puVar23 + 1);
        }
        else {
          uVar12 = (uint)*(byte *)((int)puVar23 + 1);
        }
      }
      else {
        uVar12 = (uint)*(byte *)((int)puVar23 + 1);
      }
      iVar24 = iVar24 + 1;
      puVar23 = (uint *)((int)puVar23 + uVar12);
    }
    if (bVar1) {
LAB_00438e98:
      memset(auStack_b0,0,0x80);
      iVar21 = wsta_db_get_entry_by_mac(&local_128,auStack_b0);
      uVar12 = (uint)local_82;
      if (iVar21 == 0) {
        if (uVar12 == 0) {
          uVar12 = 0xfff;
        }
        if (wportal_debug_switch == 0) {
          uVar9 = (uint)*(ushort *)((int)__src + 0xe);
        }
        else {
          iVar21 = is_target_debug_ap();
          if (iVar21 == 0) {
            uVar9 = (uint)*(ushort *)((int)__src + 0xe);
          }
          else {
            puVar5 = (undefined4 *)(local_128 >> 0x10 & 0xff);
            printf("[WPORTAL_DBG]%s()/%d Get auth packet mac: %02x:%02x:%02x:%02x:%02x:%02x, vlan_id: %d\n"
                   ,"_ac_cmcc_pkt_logout_manage",0x6ca,local_128 >> 0x18,puVar5,
                   local_128 >> 8 & 0xff,local_128 & 0xff,local_124 >> 0x18,local_124 >> 0x10 & 0xff
                   ,uVar12);
            uVar9 = (uint)*(ushort *)((int)__src + 0xe);
          }
        }
        if (uVar9 >> 8 != 0) {
          if (uVar9 >> 8 != 1) {
            if ((wportal_debug_switch == 0) || (iVar21 = is_target_debug_ap(), iVar21 == 0))
            goto LAB_00438820;
            pcVar15 = "[WPORTAL_DBG]%s()/%d Get cmcc pkt errcode not support: %x\n";
            uVar19 = 0x6dc;
            uVar12 = (uint)(*(ushort *)((int)__src + 0xe) >> 8);
            pcVar18 = "_ac_cmcc_pkt_logout_manage";
            goto LAB_004388b8;
          }
          if ((wportal_debug_switch == 0) || (iVar21 = is_target_debug_ap(), iVar21 == 0))
          goto LAB_00438820;
          pcVar15 = "[WPORTAL_DBG]%s()/%d Cmcc portal timeout\n";
          uVar19 = 0x6d6;
          pcVar18 = "_ac_cmcc_pkt_logout_manage";
          break;
        }
        uVar9 = local_128 >> 0x10 & 0xff;
        if (wportal_debug_switch != 0) {
          iVar21 = is_target_debug_ap();
          if (iVar21 == 0) {
            uVar9 = local_128 >> 0x10 & 0xff;
          }
          else {
            printf("[WPORTAL_DBG]%s()/%d Cmcc portal logout\n","_ac_cmcc_pkt_logout_manage",0x6d0);
            uVar9 = local_128 >> 0x10 & 0xff;
          }
        }
        local_118 = 0;
        local_114 = 0;
        local_110 = 0;
        local_10c = 0;
        local_108 = 0;
        local_130 = 0;
        snprintf((char *)&local_118,0x12,"%02x-%02x-%02x-%02x-%02x-%02x",local_128 >> 0x18,uVar9,
                 local_128 >> 8 & 0xff,local_128 & 0xff,local_124 >> 0x18,local_124 >> 0x10 & 0xff);
        iVar21 = json_object_new_object();
        uVar19 = json_object_new_int(5);
        json_object_object_add(iVar21,"type",uVar19);
        uVar19 = json_object_new_string(&local_118);
        json_object_object_add(iVar21,"mac",uVar19);
        uVar19 = json_object_new_int(uVar12);
        json_object_object_add(iVar21,"vlan_id",uVar19);
        uVar19 = json_object_new_int(0x14);
        json_object_object_add(iVar21,"terminate_type",uVar19);
        iVar24 = wportal_send_to_nginx_for_return(iVar21,&local_130,0);
        if (iVar24 == 0) {
          iVar24 = json_object_object_get(local_130,&DAT_00676a24);
          if (iVar24 == 0) {
LAB_00439044:
            iVar24 = -1;
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_ac_cmcc_logout",0x4a6);
            }
          }
          else {
            iVar4 = json_object_get_type(iVar24);
            if (iVar4 == 3) {
              iVar24 = json_object_get_int(iVar24);
            }
            else {
              iVar4 = json_object_get_type();
              if (iVar4 != 2) goto LAB_00439044;
              uVar25 = json_object_get_double(iVar24);
              iVar24 = __fixdfsi((int)((ulonglong)uVar25 >> 0x20),(int)uVar25);
            }
          }
          if ((wportal_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
            printf("[WPORTAL_DBG]%s()/%d Auth result: %d\n\n","_ac_cmcc_logout",0x4a8,iVar24);
          }
          if (iVar24 != 0) {
            if ((wportal_debug_switch != 0) && (iVar24 = is_target_debug_ap(), iVar24 != 0)) {
              uVar19 = 0x4ac;
              goto LAB_00439110;
            }
            goto LAB_004393ec;
          }
          _ac_cmcc_send_pkt(__s,&local_dc,6,0);
          wportal_db_nsa_del(&local_128);
        }
        else {
          if ((wportal_debug_switch != 0) && (iVar24 = is_target_debug_ap(), iVar24 != 0)) {
            uVar19 = 0x4b8;
LAB_00439110:
            printf("[WPORTAL_DBG]%s()/%d Get nginx result error\n","_ac_cmcc_logout",uVar19);
          }
LAB_004393ec:
          _ac_cmcc_send_pkt(__s,&local_dc,6,2);
        }
        if (iVar21 != 0) {
          json_object_put(iVar21);
        }
        if (local_130 != 0) {
          json_object_put();
        }
        goto LAB_00438820;
      }
      if ((wportal_debug_switch != 0) && (iVar21 = is_target_debug_ap(), iVar21 != 0)) {
        printf("[WPORTAL_DBG]%s()/%d Get wstation error\n","_ac_cmcc_pkt_logout_manage",0x6ba);
      }
    }
    else {
      memset(auStack_b0,0,0x80);
      local_ec = __src[2];
      local_f0 = 0x1000000;
      local_e8 = 0;
      local_e4 = 0;
      local_e0 = 0;
      puVar5 = (undefined4 *)0x0;
      iVar21 = wsta_db_get_entry_by_ip(0x1000000,local_ec,0,0,0,auStack_b0);
      if (iVar21 == 0) {
        local_128 = local_48;
        local_124 = CONCAT22(local_44,local_124._2_2_);
        goto LAB_00438e98;
      }
      if ((wportal_debug_switch != 0) && (iVar21 = is_target_debug_ap(), iVar21 != 0)) {
        printf("[WPORTAL_DBG]%s()/%d Get wstation error for ip %08x\n","_ac_cmcc_pkt_logout_manage",
               0x6ae,__src[2]);
      }
    }
    uVar19 = 6;
    uVar20 = 2;
LAB_00438e78:
    _ac_cmcc_send_pkt(__s,&local_dc,uVar19,uVar20);
    goto LAB_00438820;
  case 7:
    if ((wportal_debug_switch == 0) || (iVar21 = is_target_debug_ap(), iVar21 == 0))
    goto LAB_00438820;
    pcVar15 = "[WPORTAL_DBG]%s()/%d Receive AFF_ACK_AUTH packet\n";
    uVar19 = 0x743;
    pcVar18 = "_ac_cmcc_pkt_manage";
    break;
  case 9:
    if ((wportal_debug_switch == 0) || (iVar21 = is_target_debug_ap(), iVar21 == 0))
    goto LAB_00438820;
    pcVar15 = "[WPORTAL_DBG]%s()/%d Receive REQ_INFO packet\n";
    uVar19 = 0x748;
    pcVar18 = "_ac_cmcc_pkt_manage";
  }
LAB_00438864:
  printf(pcVar15,pcVar18,uVar19);
LAB_00438820:
  if (local_bc != (uint *)0x0) {
    FUN_00407df0();
  }
  goto LAB_004387a8;
}

