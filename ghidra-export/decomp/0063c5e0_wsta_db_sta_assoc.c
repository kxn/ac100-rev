// func wsta_db_sta_assoc @ 0063c5e0 size=6004

int wsta_db_sta_assoc(void *param_1,uint param_2,code *param_3,undefined4 param_4,int param_5,
                     undefined4 *param_6,int *param_7)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined1 uVar9;
  int iVar7;
  undefined2 uVar8;
  void *__src;
  uint extraout_v1;
  undefined4 extraout_v1_00;
  int iVar10;
  undefined *puVar11;
  char *pcVar12;
  void *__dest;
  undefined4 uVar13;
  uint uVar14;
  void *pvVar15;
  undefined1 *puVar16;
  undefined *local_bf8 [2];
  char local_bf0 [20];
  undefined4 local_bdc;
  undefined4 local_bd8;
  undefined4 local_bd4;
  undefined4 local_bd0;
  undefined4 local_bcc;
  undefined1 auStack_bc8 [12];
  undefined1 auStack_bbc [6];
  byte local_bb6;
  undefined1 auStack_bb2 [34];
  undefined1 auStack_b90 [64];
  undefined1 auStack_b50 [8];
  char local_b48;
  ushort local_b36;
  undefined1 auStack_afc [24];
  undefined1 auStack_ae4 [4];
  int local_ae0;
  undefined1 local_ac8;
  undefined4 local_a84;
  undefined1 auStack_a7c [24];
  undefined1 auStack_a64 [8];
  undefined4 local_a5c;
  undefined1 local_a58;
  undefined1 local_a57;
  uint local_a18;
  undefined1 auStack_a14 [24];
  undefined1 auStack_9fc [304];
  undefined1 auStack_8cc [216];
  undefined1 auStack_7f4 [304];
  undefined1 auStack_6c4 [220];
  undefined1 auStack_5e8 [20];
  int local_5d4;
  byte local_5a0;
  byte local_59f;
  byte local_59e;
  byte local_59d;
  byte local_59c;
  byte local_59b;
  undefined1 auStack_59a [542];
  undefined4 local_37c;
  undefined4 local_378;
  undefined4 local_374;
  undefined4 local_370;
  undefined4 local_36c;
  undefined1 auStack_310 [78];
  undefined1 auStack_2c2 [650];
  uint local_38;
  int local_34;
  uint local_30;
  void *local_2c;
  
  memset(auStack_a7c,0,0x80);
  memset(auStack_afc,0,0x80);
  local_bdc = 0;
  local_bd8 = 0;
  local_bd4 = 0;
  local_bd0 = 0;
  local_bcc = 0;
  local_bf0[0] = '\0';
  local_bf0[1] = '\0';
  local_bf0[2] = '\0';
  local_bf0[3] = '\0';
  local_bf0[4] = '\0';
  local_bf0[5] = '\0';
  local_bf0[6] = '\0';
  local_bf0[7] = '\0';
  local_bf0[8] = '\0';
  local_bf0[9] = '\0';
  local_bf0[10] = '\0';
  local_bf0[0xb] = '\0';
  local_bf0[0xc] = '\0';
  local_bf0[0xd] = '\0';
  local_bf0[0xe] = '\0';
  local_bf0[0xf] = '\0';
  local_bf0[0x10] = '\0';
  local_bf0[0x11] = '\0';
  local_bf0[0x12] = '\0';
  local_bf0[0x13] = '\0';
  memset(auStack_310,0,0x2d8);
  memset(auStack_5e8,0,0x2d8);
  memset(auStack_7f4,0,0x205);
  memset(auStack_9fc,0,0x205);
  local_bf8[0] = &DAT_00693fd4;
  local_bf8[1] = &DAT_00693fd0;
  memset(auStack_bc8,0,0x38);
  if ((*(int *)((int)param_1 + 0x20) < 0) ||
     (iVar4 = apmngr_db_get_ap_max(), iVar4 <= *(int *)((int)param_1 + 0x20))) {
    if (g_wsta_warning == 0) {
      return -1;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return -1;
    }
    pcVar12 = "<wsta>[warning]%s(): %d  -> invalid ap_id[%d]!\r\n";
    uVar13 = 0x675;
LAB_0063c79c:
    uVar14 = *(uint *)((int)param_1 + 0x20);
LAB_0063c7a0:
    printf(pcVar12,"wsta_db_sta_assoc",uVar13,uVar14);
    return -1;
  }
  if ((*(char *)((int)param_1 + 0x24) == '\0') ||
     (uVar14 = rdmngr_profile_get_max_rd_per_ap(), uVar14 < *(byte *)((int)param_1 + 0x24))) {
    if (g_wsta_warning == 0) {
      return -1;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return -1;
    }
    uVar14 = (uint)*(byte *)((int)param_1 + 0x24);
    pcVar12 = "<wsta>[warning]%s(): %d  -> invalid rd_id[%d]!\r\n";
    uVar13 = 0x67b;
    goto LAB_0063c7a0;
  }
  if ((*(char *)((int)param_1 + 0x25) == '\0') ||
     (uVar14 = rdmngr_profile_get_max_wlan_per_rd(), uVar14 < *(byte *)((int)param_1 + 0x25))) {
    if (g_wsta_warning == 0) {
      return -1;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return -1;
    }
    uVar14 = (uint)*(byte *)((int)param_1 + 0x25);
    pcVar12 = "<wsta>[warning]%s(): %d  -> invalid wlan_id[%d]!\r\n";
    uVar13 = 0x681;
    goto LAB_0063c7a0;
  }
  iVar4 = apmngr_db_entry_get_by_id(*(undefined2 *)((int)param_1 + 0x22),auStack_5e8);
  if ((iVar4 != 0) ||
     (iVar4 = apmngr_db_is_led_wifi_close(*(undefined2 *)((int)param_1 + 0x22)), iVar4 != 0)) {
    if (g_wsta_warning == 0) {
      return -1;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return -1;
    }
    pcVar12 = 
    "<wsta>[warning]%s(): %d  -> ap_id[%d]\'s wifi is closed by LED or entry not found!\r\n";
    uVar13 = 0x687;
    goto LAB_0063c79c;
  }
  iVar4 = uac_wservice_get_wserv_id
                    (*(undefined4 *)((int)param_1 + 0x20),*(undefined1 *)((int)param_1 + 0x24),
                     *(undefined1 *)((int)param_1 + 0x25));
  if (iVar4 == -1) {
    if (g_wsta_warning == 0) {
      return -1;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return -1;
    }
    printf("<wsta>[warning]%s(): %d  -> entry->ap_id[%d], entry->rd_id[%d], entry->wlan_id[%d] invalid!\r\n"
           ,"wsta_db_sta_assoc",0x68e,*(undefined4 *)((int)param_1 + 0x20),
           (uint)*(byte *)((int)param_1 + 0x24),(uint)*(byte *)((int)param_1 + 0x25));
    return -1;
  }
  if (*(int *)((int)param_1 + 0x68) == 0) {
    if ((*(uint *)((int)param_1 + 0x6c) & 0xffff0000) == 0) {
      if (g_wsta_warning == 0) {
        return -1;
      }
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        return -1;
      }
      printf("<wsta>[warning]%s(): %d  -> invalid mac addr!\r\n","wsta_db_sta_assoc",0x694);
      return -1;
    }
    uVar13 = *(undefined4 *)((int)param_1 + 0x20);
  }
  else {
    uVar13 = *(undefined4 *)((int)param_1 + 0x20);
  }
  uVar14 = rdmngr_db_generate_rd_id(uVar13,*(undefined1 *)((int)param_1 + 0x24));
  iVar5 = rdmngr_db_rd_entry_get(uVar14,auStack_b50);
  if (iVar5 != 0) {
    if (g_wsta_warning == 0) {
      return -1;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return -1;
    }
    pcVar12 = "<wsta>[warning]%s(): %d  -> rdmngr_db_rd_entry_get() fail, rd_id=%d\r\n";
    uVar13 = 0x69a;
    goto LAB_0063c7a0;
  }
  local_34 = wsta_db_get_rd_sta_num
                       (*(undefined4 *)((int)param_1 + 0x20),*(undefined1 *)((int)param_1 + 0x24));
  if (local_34 == -1) {
    if (g_wsta_warning == 0) {
      return -1;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return -1;
    }
    pcVar12 = "<wsta>[warning]%s(): %d  -> wsta_db_get_rd_sta_num() fail, rd_id=%d\r\n";
    uVar13 = 0x6a1;
    goto LAB_0063c7a0;
  }
  local_38 = 0;
  if (local_5d4 != 5) {
    iVar5 = apmngr_db_capacity_support(*(undefined2 *)((int)param_1 + 0x22),1,0);
    local_38 = (uint)(iVar5 != 0);
  }
  iVar5 = gettimeofday((timeval *)((int)param_1 + 0x70),(__timezone_ptr_t)0x0);
  if (iVar5 != 0) {
    if ((g_wsta_warning != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("<wsta>[warning]%s(): %d  -> gettimeofday() fail!\r\n","wsta_db_sta_assoc",0x6a9);
    }
    memset((timeval *)((int)param_1 + 0x70),0,8);
  }
  FUN_00407e70();
  *(uint *)((int)param_1 + 0x78) = extraout_v1;
  if (param_2 != 0) {
    iVar5 = extraout_v1 - param_2;
    if (extraout_v1 <= param_2) {
      iVar5 = 0;
    }
    *(int *)((int)param_1 + 0x78) = iVar5;
    iVar5 = *(uint *)((int)param_1 + 0x70) - param_2;
    if (*(uint *)((int)param_1 + 0x70) <= param_2) {
      iVar5 = 0;
    }
    *(int *)((int)param_1 + 0x70) = iVar5;
  }
  FUN_00407e70();
  *(undefined4 *)((int)param_1 + 0x38) = extraout_v1_00;
  *(undefined1 *)((int)param_1 + 0x34) = 0;
  if (local_38 == 0) {
    uVar14 = *(uint *)((int)param_1 + 100) & 0xfffffffe;
  }
  else {
    uVar14 = *(uint *)((int)param_1 + 100) | 1;
  }
  *(uint *)((int)param_1 + 100) = uVar14;
  *(undefined4 *)((int)param_1 + 0x18) = 1;
  if (param_6 != (undefined4 *)0x0) {
    memset(param_6,0,8);
  }
  pvVar15 = (void *)((int)param_1 + 0x68);
  FUN_004082d0(DAT_007cc6bc,0xffffffff);
  iVar5 = FUN_00407fa0(DAT_007cc6cc,pvVar15);
  if (iVar5 == 0) {
    if ((g_wsta_debug != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
      printf("<wsta>[debug]%s(): %d  -> can`t find ori wsta.\r\n","wsta_db_sta_assoc",0x6c8);
    }
    __src = (void *)FUN_00407fa0(DAT_007cc718,pvVar15);
    if (__src == (void *)0x0) {
LAB_0063d46c:
      iVar10 = 3;
      if ((int)(uint)local_b36 <= local_34) goto LAB_0063caf4;
      if (g_wsta_debug == 0) {
        uVar13 = *(undefined4 *)((int)param_1 + 0x20);
      }
      else {
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          uVar13 = *(undefined4 *)((int)param_1 + 0x20);
        }
        else {
          printf("<wsta>[debug]%s(): %d  -> new sta assoc[%02X:%02X:%02X:%02X:%02X:%02X].\r\n",
                 "wsta_db_sta_assoc",0x814,(uint)*(byte *)((int)param_1 + 0x68),
                 (uint)*(byte *)((int)param_1 + 0x69),(uint)*(byte *)((int)param_1 + 0x6a),
                 (uint)*(byte *)((int)param_1 + 0x6b),(uint)*(byte *)((int)param_1 + 0x6c),
                 (uint)*(byte *)((int)param_1 + 0x6d));
          uVar13 = *(undefined4 *)((int)param_1 + 0x20);
        }
      }
      *(undefined4 *)((int)param_1 + 0x28) = uVar13;
      *(undefined1 *)((int)param_1 + 0x2c) = *(undefined1 *)((int)param_1 + 0x24);
      *(undefined1 *)((int)param_1 + 0x2d) = *(undefined1 *)((int)param_1 + 0x25);
      if ((g_wsta_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
        printf("<wsta>[debug]%s(): %d  -> set original ap\'s id : %d, rd id : %d, wlan id : %d\n\r\n"
               ,"wsta_db_sta_assoc",0x819,*(undefined4 *)((int)param_1 + 0x28),
               (uint)*(byte *)((int)param_1 + 0x2c),(uint)*(byte *)((int)param_1 + 0x2d));
      }
      iVar5 = FUN_004085b0(DAT_007cc6c0);
      if (iVar5 == -1) {
        iVar10 = 4;
        if ((g_wsta_warning == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_0063caf4;
        uVar13 = 0x81e;
LAB_0063d644:
        iVar10 = 4;
        printf("<wsta>[warning]%s(): %d  -> uac_id_alloc() fail!\r\n","wsta_db_sta_assoc",uVar13);
        goto LAB_0063caf4;
      }
      iVar10 = iVar5 * 0x80;
      pvVar15 = (void *)(DAT_007cc6c8 + iVar10);
      if (*(int *)((int)pvVar15 + 0x18) == 0) {
        *(int *)((int)param_1 + 0x1c) = iVar5;
        memcpy(pvVar15,param_1,0x80);
        FUN_004086b0(*(int *)(*(int *)(DAT_007cc6e4 + *(int *)((int)param_1 + 0x20) * 4) +
                             (*(byte *)((int)param_1 + 0x24) - 1) * 4) +
                     (*(byte *)((int)param_1 + 0x25) - 1) * 0xc,DAT_007cc6c8 + iVar10);
        FUN_004086b0(&DAT_007cc6d8,DAT_007cc6c8 + iVar10 + 0xc);
        iVar7 = FUN_00408380(DAT_007cc6cc,DAT_007cc6c8 + iVar10);
        if (iVar7 == 0) {
          DAT_007cc73c = DAT_007cc73c + 1;
          if (DAT_007cc710 == 0) {
            DAT_007cc710 = DAT_007cc6c8 + iVar10 + 0xc;
          }
          FUN_00407f30(DAT_007cc6bc);
          iVar4 = uac_wservice_get_entry_by_id(iVar4,auStack_7f4);
          if (iVar4 == 0) {
            if ((param_7 == (int *)0x0) || (*param_7 == 0)) {
              snprintf(local_bf0,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_5a0,
                       (uint)local_59f,(uint)local_59e,(uint)local_59d,(uint)local_59c,
                       (uint)local_59b);
              snprintf((char *)&local_bdc,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",
                       (uint)*(byte *)((int)param_1 + 0x68),(uint)*(byte *)((int)param_1 + 0x69),
                       (uint)*(byte *)((int)param_1 + 0x6a),(uint)*(byte *)((int)param_1 + 0x6b),
                       (uint)*(byte *)((int)param_1 + 0x6c),(uint)*(byte *)((int)param_1 + 0x6d));
              memset(auStack_b90,0,0x40);
              FUN_00408190(local_37c,local_378,local_374,local_370,local_36c,auStack_b90,0x40,"---")
              ;
              loggerk_reg(0x5b,0x3a99,1,&local_bdc,1,auStack_59a,1,auStack_b90,1,local_bf0,1,
                          auStack_6c4,1,local_bf8[local_b48],0);
            }
            iVar4 = wsta_db_get_ap_sta_num(*(undefined4 *)((int)param_1 + 0x20));
            if (nms_ap_overload_threshold < iVar4) {
              trigger_sta_overload_nms_event(&local_5a0);
            }
          }
          _uac_wstation_do_event(0,param_1);
          return 0;
        }
        iVar10 = -1;
        if ((g_wsta_error == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_0063caf4;
        pcVar12 = "<wsta>[error]%s(): %d  -> uac_hash_add() fail, wsra_id = %d!\r\n";
        uVar13 = 0x830;
      }
      else {
        iVar10 = -1;
        if ((g_wsta_warning == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_0063caf4;
        pcVar12 = "<wsta>[warning]%s(): %d  -> entry.id[%d] has been used!\r\n";
        uVar13 = 0x825;
      }
    }
    else {
      if (param_5 == 0) {
LAB_0063d42c:
        if ((g_wsta_debug != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
          printf("<wsta>[debug]%s(): %d  -> get the sta in tmp hash.remove it.\r\n",
                 "wsta_db_sta_assoc",0x6f2);
        }
        iVar10 = FUN_00407f40(DAT_007cc718,__src);
        if (iVar10 == 0) {
          if ((g_wsta_debug != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
            printf("<wsta>[debug]%s(): %d  -> remove sta in tmp hash success.\r\n",
                   "wsta_db_sta_assoc",0x6fa);
          }
          FUN_00408500((int)__src + 0xc);
        }
        else if ((g_wsta_error != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
          printf("<wsta>[error]%s(): %d  -> uac_hash_remove() fail, wsta_entry->id=%d!\r\n",
                 "wsta_db_sta_assoc",0x6f5,*(undefined4 *)((int)__src + 0x1c));
        }
        wsta_free(__src);
        if (iVar5 != 0) goto LAB_0063cac0;
        goto LAB_0063d46c;
      }
      iVar5 = FUN_004085b0(DAT_007cc6c0);
      if (iVar5 == -1) {
        iVar10 = 4;
        if ((g_wsta_warning == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_0063caf4;
        uVar13 = 0x6d2;
        goto LAB_0063d644;
      }
      local_30 = iVar5 * 0x80;
      __dest = (void *)(DAT_007cc6c8 + local_30);
      if (*(int *)((int)__dest + 0x18) == 0) {
        *(int *)((int)__src + 0x1c) = iVar5;
        memcpy(__dest,__src,0x80);
        if ((g_wsta_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          printf("<wsta>[debug]%s(): %d  -> add tmp sta to ori hash.\n\r\n","wsta_db_sta_assoc",
                 0x6df);
        }
        iVar5 = FUN_00408380(DAT_007cc6cc,DAT_007cc6c8 + *(int *)((int)__src + 0x1c) * 0x80);
        if (iVar5 != 0) {
          if ((g_wsta_error != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
            printf("<wsta>[error]%s(): %d  -> uac_hash_add() fail, wsra_id = %d!\r\n",
                   "wsta_db_sta_assoc",0x6ed,*(undefined4 *)((int)__src + 0x1c));
          }
          iVar10 = -1;
          wsta_free(DAT_007cc6c8 + *(int *)((int)__src + 0x1c) * 0x80);
          goto LAB_0063caf4;
        }
        if ((g_wsta_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          printf("<wsta>[debug]%s(): %d  -> add hash SUCCESS.\n\r\n","wsta_db_sta_assoc",0x6e2);
        }
        FUN_004086b0(&DAT_007cc6d8,DAT_007cc6c8 + *(int *)((int)__src + 0x1c) * 0x80 + 0xc);
        iVar5 = DAT_007cc6c8 + *(int *)((int)__src + 0x1c) * 0x80;
        FUN_004086b0(*(int *)(*(int *)(DAT_007cc6e4 + *(int *)(iVar5 + 0x20) * 4) +
                             (*(byte *)(iVar5 + 0x24) - 1) * 4) +
                     (*(byte *)(iVar5 + 0x25) - 1) * 0xc);
        if (DAT_007cc710 == 0) {
          DAT_007cc710 = DAT_007cc6c8 + local_30 + 0xc;
        }
        iVar5 = FUN_00407fa0(DAT_007cc6cc,pvVar15);
        goto LAB_0063d42c;
      }
      iVar10 = -1;
      if ((g_wsta_warning == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_0063caf4;
      pcVar12 = "<wsta>[warning]%s(): %d  -> entry.id[%d] has been used!\r\n";
      uVar13 = 0x6d9;
    }
    iVar10 = -1;
    printf(pcVar12,"wsta_db_sta_assoc",uVar13,iVar5);
LAB_0063caf4:
    FUN_00407f30(DAT_007cc6bc);
    if (iVar10 != 3) {
      return iVar10;
    }
    iVar4 = wsta_db_get_ap_sta_num(*(undefined4 *)((int)param_1 + 0x20));
    if (iVar4 <= nms_ap_overload_threshold) {
      return 3;
    }
    iVar4 = apmngr_db_entry_get_by_id(*(undefined2 *)((int)param_1 + 0x22),auStack_5e8);
    if (iVar4 != 0) {
      return 3;
    }
    trigger_sta_overload_nms_event(&local_5a0);
    return 3;
  }
LAB_0063cac0:
  if (g_wsta_warning == 0) {
    iVar10 = *(int *)(iVar5 + 0x20);
  }
  else {
    iVar10 = is_target_debug_ap();
    if (iVar10 == 0) {
      iVar10 = *(int *)(iVar5 + 0x20);
    }
    else {
      printf("<wsta>[warning]%s(): %d  -> entry->acs_uptime = %d, hash acs_uptime = %d\r\n",
             "wsta_db_sta_assoc",0x703,*(undefined4 *)((int)param_1 + 0x78),
             *(undefined4 *)(iVar5 + 0x78));
      iVar10 = *(int *)(iVar5 + 0x20);
    }
  }
  if (iVar10 == *(int *)((int)param_1 + 0x20)) {
    if ((*(uint *)(iVar5 + 0x24) & 0xffff0000) != (*(uint *)((int)param_1 + 0x24) & 0xffff0000)) {
      if (*(char *)(iVar5 + 0x24) != *(char *)((int)param_1 + 0x24)) goto LAB_0063cae0;
      goto LAB_0063cb7c;
    }
    bVar2 = false;
    if ((uint)(*(int *)((int)param_1 + 0x78) - *(int *)(iVar5 + 0x78)) < 6) {
      if ((g_wsta_warning != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("<wsta>[warning]%s(): %d  -> wsta[%d] ap[%d] rd[%d] wlan[%d] assoc duplicate!\r\n",
               "wsta_db_sta_assoc",0x711,*(undefined4 *)((int)param_1 + 0x1c),
               *(undefined4 *)((int)param_1 + 0x20),(uint)*(byte *)((int)param_1 + 0x24),
               (uint)*(byte *)((int)param_1 + 0x25));
      }
      DAT_007cc740 = DAT_007cc740 + 1;
      iVar10 = 1;
      if ((param_5 != 0) && (param_6 != (undefined4 *)0x0)) {
        *param_6 = 1;
        *(undefined2 *)(param_6 + 1) = *(undefined2 *)(iVar5 + 0x2e);
      }
      goto LAB_0063caf4;
    }
  }
  else {
LAB_0063cae0:
    iVar10 = 3;
    if ((int)(uint)local_b36 <= local_34) goto LAB_0063caf4;
LAB_0063cb7c:
    bVar2 = true;
  }
  FUN_00408500(iVar5);
  FUN_004086b0(*(int *)(*(int *)(DAT_007cc6e4 + *(int *)((int)param_1 + 0x20) * 4) +
                       (*(byte *)((int)param_1 + 0x24) - 1) * 4) +
               (*(byte *)((int)param_1 + 0x25) - 1) * 0xc,iVar5);
  local_2c = (void *)(iVar5 + 0x18);
  memcpy(auStack_a64,local_2c,0x68);
  uVar14 = *(uint *)(iVar5 + 0x20);
  if (uVar14 == *(uint *)((int)param_1 + 0x20)) {
    local_34 = 0xffffffff;
    bVar3 = false;
    local_30 = 0xffffffff;
  }
  else {
    if (g_wsta_debug != 0) {
      iVar10 = is_target_debug_ap();
      if (iVar10 == 0) {
        uVar14 = *(uint *)(iVar5 + 0x20);
      }
      else {
        printf("<wsta>[debug]%s(): %d  -> wsta[%d] roam from ap[%d] to ap [%d]!\r\n",
               "wsta_db_sta_assoc",0x729,*(undefined4 *)((int)param_1 + 0x1c),
               *(undefined4 *)(iVar5 + 0x20),*(undefined4 *)((int)param_1 + 0x20));
        uVar14 = *(uint *)(iVar5 + 0x20);
      }
    }
    local_34 = *(undefined4 *)((int)param_1 + 0x20);
    *(int *)(iVar5 + 0x20) = local_34;
    l_wsta_info_stat = l_wsta_info_stat + 1;
    if (local_38 == 0) {
      uVar6 = *(uint *)(iVar5 + 100) & 0xfffffffe;
    }
    else {
      uVar6 = *(uint *)(iVar5 + 100) | 1;
    }
    bVar3 = true;
    *(uint *)(iVar5 + 100) = uVar6;
    local_30 = uVar14;
  }
  local_38 = 0;
  if (*(char *)(iVar5 + 0x24) != *(char *)((int)param_1 + 0x24)) {
    if (g_wsta_debug == 0) {
      uVar9 = *(undefined1 *)((int)param_1 + 0x24);
    }
    else {
      iVar10 = is_target_debug_ap();
      if (iVar10 == 0) {
        uVar9 = *(undefined1 *)((int)param_1 + 0x24);
      }
      else {
        printf("<wsta>[debug]%s(): %d  -> wsta[%d] roam from ap[%d]\'s rd[%d] to rd[%d]!\r\n",
               "wsta_db_sta_assoc",0x73d,*(undefined4 *)((int)param_1 + 0x1c),
               *(undefined4 *)((int)param_1 + 0x20),(uint)*(byte *)(iVar5 + 0x24),
               (uint)*(byte *)((int)param_1 + 0x24));
        uVar9 = *(undefined1 *)((int)param_1 + 0x24);
      }
    }
    *(undefined1 *)(iVar5 + 0x24) = uVar9;
    DAT_007cc734 = DAT_007cc734 + 1;
    local_38 = 1;
  }
  if (*(char *)(iVar5 + 0x25) != *(char *)((int)param_1 + 0x25)) {
    if (g_wsta_debug == 0) {
      uVar9 = *(undefined1 *)((int)param_1 + 0x25);
    }
    else {
      iVar10 = is_target_debug_ap();
      if (iVar10 == 0) {
        uVar9 = *(undefined1 *)((int)param_1 + 0x25);
      }
      else {
        printf("<wsta>[debug]%s(): %d  -> wsta[%d] roam from ap[%d] rd[%d]\'s wlan[%d] to wlan[%d]!\r\n"
               ,"wsta_db_sta_assoc",0x747,*(undefined4 *)((int)param_1 + 0x1c),
               *(undefined4 *)((int)param_1 + 0x20),(uint)*(byte *)((int)param_1 + 0x24),
               (uint)*(byte *)(iVar5 + 0x25),(uint)*(byte *)((int)param_1 + 0x25));
        uVar9 = *(undefined1 *)((int)param_1 + 0x25);
      }
    }
    *(undefined1 *)(iVar5 + 0x25) = uVar9;
    DAT_007cc738 = DAT_007cc738 + 1;
  }
  *(undefined1 *)(iVar5 + 0x35) = *(undefined1 *)((int)param_1 + 0x35);
  *(undefined4 *)(iVar5 + 0x78) = *(undefined4 *)((int)param_1 + 0x78);
  if (param_5 == 0) {
    uVar8 = *(undefined2 *)((int)param_1 + 0x2e);
LAB_0063d2c4:
    *(undefined2 *)(iVar5 + 0x2e) = uVar8;
  }
  else {
    if (local_38 == 0 && !bVar3) {
      uVar8 = *(undefined2 *)((int)param_1 + 0x2e);
      goto LAB_0063d2c4;
    }
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = 1;
      *(undefined2 *)(param_6 + 1) = *(undefined2 *)(iVar5 + 0x2e);
    }
  }
  memcpy(auStack_ae4,local_2c,0x68);
  FUN_00407f30(DAT_007cc6bc);
  if (bVar3) {
    iVar5 = uac_wservice_get_wserv_id(local_a5c,local_a58,local_a57);
    uVar13 = rdmngr_db_generate_rd_id(local_a5c,local_a58);
    iVar10 = rdmngr_db_get_rd_freq_band(uVar13);
    if ((((iVar10 == -1) || (iVar5 == -1)) ||
        (iVar7 = apmngr_db_entry_get_by_id(local_30 & 0xffff,auStack_310), iVar7 != 0)) ||
       ((iVar7 = uac_wservice_get_entry_by_id(iVar5,auStack_9fc), iVar7 != 0 ||
        (iVar7 = uac_wservice_get_entry_by_id(iVar4,auStack_7f4), iVar7 != 0)))) goto LAB_0063cd28;
    iVar7 = wsta_db_get_ap_sta_num(local_34);
    if (nms_ap_overload_threshold < iVar7) {
      trigger_sta_overload_nms_event(&local_5a0);
    }
    if (iVar5 != iVar4) {
      bVar1 = *(byte *)((int)param_1 + 0x69);
LAB_0063cf00:
      snprintf((char *)&local_bdc,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",
               (uint)*(byte *)((int)param_1 + 0x68),(uint)bVar1,(uint)*(byte *)((int)param_1 + 0x6a)
               ,(uint)*(byte *)((int)param_1 + 0x6b),(uint)*(byte *)((int)param_1 + 0x6c),
               (uint)*(byte *)((int)param_1 + 0x6d));
      snprintf(local_bf0,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_5a0,(uint)local_59f,
               (uint)local_59e,(uint)local_59d,(uint)local_59c,(uint)local_59b);
      loggerk_reg(0x5b,0x3a9a,1,&local_bdc,0);
      memset(auStack_b90,0,0x40);
      FUN_00408190(local_37c,local_378,local_374,local_370,local_36c,auStack_b90,0x40,"---");
      loggerk_reg(0x5b,0x3a99,1,&local_bdc,1,auStack_59a,1,auStack_b90,1,local_bf0,1,auStack_6c4,1,
                  local_bf8[local_b48],0);
      goto LAB_0063cd28;
    }
    if (param_7 == (int *)0x0) {
      bVar1 = *(byte *)((int)param_1 + 0x69);
    }
    else {
      if (*param_7 != 0) goto LAB_0063cd28;
      bVar1 = *(byte *)((int)param_1 + 0x69);
    }
    snprintf((char *)&local_bdc,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",
             (uint)*(byte *)((int)param_1 + 0x68),(uint)bVar1,(uint)*(byte *)((int)param_1 + 0x6a),
             (uint)*(byte *)((int)param_1 + 0x6b),(uint)*(byte *)((int)param_1 + 0x6c),
             (uint)*(byte *)((int)param_1 + 0x6d));
    puVar16 = auStack_2c2;
    puVar11 = local_bf8[iVar10];
  }
  else {
    if (!bVar2) goto LAB_0063cd28;
    iVar5 = uac_wservice_get_wserv_id(local_a5c,local_a58,local_a57);
    uVar13 = rdmngr_db_generate_rd_id(local_a5c,local_a58);
    iVar10 = rdmngr_db_get_rd_freq_band(uVar13);
    if (((iVar10 == -1) || (iVar5 == -1)) ||
       ((iVar7 = uac_wservice_get_entry_by_id(iVar5,auStack_9fc), iVar7 != 0 ||
        (iVar7 = uac_wservice_get_entry_by_id(iVar4,auStack_7f4), iVar7 != 0)))) goto LAB_0063cd28;
    if (iVar5 != iVar4) {
      bVar1 = *(byte *)((int)param_1 + 0x69);
      goto LAB_0063cf00;
    }
    if (iVar10 == local_b48) goto LAB_0063cd28;
    if (param_7 == (int *)0x0) {
      bVar1 = *(byte *)((int)param_1 + 0x69);
    }
    else {
      if (*param_7 != 0) goto LAB_0063cd28;
      bVar1 = *(byte *)((int)param_1 + 0x69);
    }
    snprintf((char *)&local_bdc,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",
             (uint)*(byte *)((int)param_1 + 0x68),(uint)bVar1,(uint)*(byte *)((int)param_1 + 0x6a),
             (uint)*(byte *)((int)param_1 + 0x6b),(uint)*(byte *)((int)param_1 + 0x6c),
             (uint)*(byte *)((int)param_1 + 0x6d));
    puVar16 = auStack_59a;
    puVar11 = local_bf8[iVar10];
  }
  loggerk_reg(0x5b,0x3a9e,1,&local_bdc,1,puVar16,1,auStack_8cc,1,puVar11,1,auStack_59a,1,auStack_6c4
              ,1,local_bf8[local_b48],0);
LAB_0063cd28:
  if ((((local_38 != 0 || bVar3) && (param_3 != (code *)0x0)) &&
      ((*param_3)(auStack_a7c,param_4), param_7 != (int *)0x0)) &&
     ((param_7[1] == 0 &&
      ((iVar4 = wsta_db_get_mac_entry_by_mld(pvVar15,auStack_bc8), iVar4 == 0 ||
       (iVar4 = wsta_db_get_mac_entry_by_peer(pvVar15,auStack_bc8), iVar4 == 0)))))) {
    iVar4 = wsta_db_get_entry_by_mac(auStack_bbc,auStack_a7c);
    if ((iVar4 == 0) && (iVar4 = memcmp(pvVar15,auStack_a14,6), iVar4 != 0)) {
      (*param_3)(auStack_a7c,param_4);
    }
    for (uVar14 = 0; uVar14 < local_bb6; uVar14 = uVar14 + 1 & 0xff) {
      puVar16 = auStack_bb2 + uVar14 * 0xc;
      iVar4 = memcmp(auStack_bbc,puVar16,6);
      if (((iVar4 != 0) && (iVar4 = wsta_db_get_entry_by_mac(puVar16,auStack_a7c), iVar4 == 0)) &&
         (iVar4 = memcmp(pvVar15,puVar16,6), iVar4 != 0)) {
        (*param_3)(auStack_a7c,param_4);
      }
    }
  }
  if (bVar2) {
    iVar4 = 2;
    local_ac8 = 1;
    iVar5 = DAT_007cc6c8 + local_ae0 * 0x80;
    *(undefined1 *)(iVar5 + 0x34) = 1;
    *(undefined4 *)(iVar5 + 0x78) = local_a84;
  }
  else {
    iVar4 = 0;
    local_a18 = local_a18 | 2;
  }
  if ((param_7 != (int *)0x0) && (param_7[1] == 0)) {
    iVar5 = wsta_db_get_mac_entry_by_mld(pvVar15,auStack_bc8);
    if ((iVar5 == 0) || (iVar5 = wsta_db_get_mac_entry_by_peer(pvVar15,auStack_bc8), iVar5 == 0)) {
      for (uVar14 = 0; uVar14 < local_bb6; uVar14 = uVar14 + 1 & 0xff) {
        puVar16 = auStack_bb2 + uVar14 * 0xc;
        iVar5 = memcmp(auStack_bbc,puVar16,6);
        if ((iVar5 != 0) && (iVar5 = memcmp(pvVar15,puVar16,6), iVar5 != 0)) {
          wsta_db_free_sta_by_mac(puVar16,0,0);
        }
      }
      iVar5 = memcmp(pvVar15,auStack_bbc,6);
      if (iVar5 != 0) {
        wsta_db_free_sta_by_mac(auStack_bbc,0,0);
      }
      wsta_db_free_mlo_mac_entry(auStack_bc8);
    }
  }
  _uac_wstation_do_event(1,auStack_a7c);
  _uac_wstation_do_event(0,auStack_afc);
  return iVar4;
}

