// func wserv_test_main @ 005f5edc size=1

/* WARNING: Removing unreachable block (ram,0x005f602c) */
/* WARNING: Removing unreachable block (ram,0x005f61d4) */
/* WARNING: Removing unreachable block (ram,0x005f60d4) */
/* WARNING: Removing unreachable block (ram,0x005f6060) */
/* WARNING: Removing unreachable block (ram,0x005f60a4) */
/* WARNING: Removing unreachable block (ram,0x005f61a4) */
/* WARNING: Removing unreachable block (ram,0x005f6008) */
/* WARNING: Removing unreachable block (ram,0x005f62c4) */
/* WARNING: Removing unreachable block (ram,0x005f60fc) */
/* WARNING: Removing unreachable block (ram,0x005f6044) */
/* WARNING: Removing unreachable block (ram,0x005f6158) */
/* WARNING: Removing unreachable block (ram,0x005f61f4) */

undefined4 wserv_test_main(int param_1,int param_2)

{
  undefined1 *puVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined1 auStack_238 [132];
  char acStack_1b4 [151];
  undefined1 auStack_11d [17];
  int iStack_10c;
  char acStack_108 [50];
  undefined1 auStack_d6 [8];
  undefined1 auStack_ce [4];
  undefined1 auStack_ca [4];
  undefined1 auStack_c6 [4];
  undefined1 auStack_c2 [4];
  char acStack_be [40];
  undefined1 auStack_96 [8];
  char acStack_8e [94];
  int iStack_30;
  
  iVar10 = 0x10;
  wserv_db_init();
  uVar3 = time((time_t *)0x0);
  srand(uVar3);
  if (param_1 == 2) {
    iVar10 = atoi(*(char **)(param_2 + 4));
  }
  iVar9 = 0;
  uVar4 = rdmngr_profile_get_max_wlan_per_rd();
  iStack_30 = wserv_calloc(uVar4,6);
  if (iStack_30 == 0) {
    uVar4 = 0xffffffff;
    if ((g_wserv_error != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
      printf("<wserv>[error]%s(): %d  -> no memory!\r\n","wserv_test_main",0x18e6);
    }
  }
  else {
    for (; iVar8 = 0, iVar9 < iVar10; iVar9 = iVar9 + 1) {
      memset(auStack_238,0,0x205);
      uVar3 = rand();
      if (l_wserv_profile == 0) {
        trap(7);
      }
      snprintf(acStack_108,0x32,"ssid_%d",uVar3 % l_wserv_profile);
      uVar3 = rand();
      if (l_wserv_profile == 0) {
        trap(7);
      }
      snprintf(acStack_1b4,0x97,"describle_%d",uVar3 % l_wserv_profile);
      iStack_10c = rand();
      iStack_10c = iStack_10c % 3;
      if (iStack_10c == 0) {
        iStack_10c = 1;
      }
      iVar8 = rand();
      uVar3 = (uint)auStack_d6 & 3;
      puVar2 = (uint *)(auStack_d6 + -uVar3);
      *puVar2 = *puVar2 & -1 << (4 - uVar3) * 8 | (uint)(iVar8 % 2) >> uVar3 * 8;
      puVar1 = auStack_d6 + 3;
      uVar3 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar3) =
           *(uint *)(puVar1 + -uVar3) & 0xffffffffU >> (uVar3 + 1) * 8 |
           iVar8 % 2 << (3 - uVar3) * 8;
      iVar8 = rand();
      uVar3 = (uint)auStack_11d & 3;
      puVar2 = (uint *)(auStack_11d + -uVar3);
      *puVar2 = *puVar2 & -1 << (4 - uVar3) * 8 | (uint)(iVar8 % 2) >> uVar3 * 8;
      puVar1 = auStack_11d + 3;
      uVar3 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar3) =
           *(uint *)(puVar1 + -uVar3) & 0xffffffffU >> (uVar3 + 1) * 8 |
           iVar8 % 2 << (3 - uVar3) * 8;
      iVar8 = rand();
      uVar11 = iVar8 % 5;
      uVar3 = (uint)auStack_ce & 3;
      puVar2 = (uint *)(auStack_ce + -uVar3);
      *puVar2 = *puVar2 & -1 << (4 - uVar3) * 8 | uVar11 >> uVar3 * 8;
      puVar1 = auStack_ce + 3;
      uVar3 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar3) =
           *(uint *)(puVar1 + -uVar3) & 0xffffffffU >> (uVar3 + 1) * 8 | uVar11 << (3 - uVar3) * 8;
      if (uVar11 == 1) {
        iVar8 = rand();
        uVar11 = iVar8 % 4;
        puVar1 = auStack_ce + 4;
        uVar3 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar3) =
             *(uint *)(puVar1 + -uVar3) & -1 << (4 - uVar3) * 8 | uVar11 >> uVar3 * 8;
        puVar1 = auStack_ce + 7;
        uVar3 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar3) =
             *(uint *)(puVar1 + -uVar3) & 0xffffffffU >> (uVar3 + 1) * 8 | uVar11 << (3 - uVar3) * 8
        ;
        if (uVar11 == 0) {
          puVar1 = auStack_ce + 4;
          uVar3 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar3) =
               *(uint *)(puVar1 + -uVar3) & -1 << (4 - uVar3) * 8 | 3U >> uVar3 * 8;
          puVar1 = auStack_ce + 7;
          uVar3 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar3) =
               *(uint *)(puVar1 + -uVar3) & 0xffffffffU >> (uVar3 + 1) * 8 | 3 << (3 - uVar3) * 8;
        }
        iVar8 = rand();
        puVar1 = auStack_ce + 8;
        uVar3 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar3) =
             *(uint *)(puVar1 + -uVar3) & -1 << (4 - uVar3) * 8 | (uint)(iVar8 % 3) >> uVar3 * 8;
        puVar1 = auStack_ce + 0xb;
        uVar3 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar3) =
             *(uint *)(puVar1 + -uVar3) & 0xffffffffU >> (uVar3 + 1) * 8 |
             iVar8 % 3 << (3 - uVar3) * 8;
        iVar8 = rand();
        puVar1 = auStack_ce + 0xc;
        uVar3 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar3) =
             *(uint *)(puVar1 + -uVar3) & -1 << (4 - uVar3) * 8 |
             (uint)(iVar8 % 0x93a80) >> uVar3 * 8;
        puVar1 = auStack_ce + 0xf;
        uVar3 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar3) =
             *(uint *)(puVar1 + -uVar3) & 0xffffffffU >> (uVar3 + 1) * 8 |
             iVar8 % 0x93a80 << (3 - uVar3) * 8;
        uVar3 = rand();
        if (l_wserv_profile == 0) {
          trap(7);
        }
        uVar11 = snprintf(auStack_ce + 0x10,0x41,"psk%d",uVar3 % l_wserv_profile);
        uVar3 = (uint)auStack_ce & 3;
        uVar3 = *(int *)(auStack_ce + -uVar3) << uVar3 * 8 | uVar11 & 0xffffffffU >> (4 - uVar3) * 8
        ;
      }
      else {
        uVar3 = (uint)auStack_ce & 3;
        uVar3 = *(int *)(auStack_ce + -uVar3) << uVar3 * 8 | uVar11 & 0xffffffffU >> (4 - uVar3) * 8
        ;
      }
      uVar11 = (uint)(auStack_ce + 3) & 3;
      uVar3 = uVar3 & -1 << (uVar11 + 1) * 8 |
              *(uint *)(auStack_ce + 3 + -uVar11) >> (3 - uVar11) * 8;
      if (uVar3 == 4) {
        puVar1 = auStack_ce + 4;
        uVar3 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar3) =
             *(uint *)(puVar1 + -uVar3) & -1 << (4 - uVar3) * 8 | 3U >> uVar3 * 8;
        puVar1 = auStack_ce + 7;
        uVar3 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar3) =
             *(uint *)(puVar1 + -uVar3) & 0xffffffffU >> (uVar3 + 1) * 8 | 3 << (3 - uVar3) * 8;
        puVar1 = auStack_ce + 8;
        uVar3 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar3) =
             *(uint *)(puVar1 + -uVar3) & -1 << (4 - uVar3) * 8 | 2U >> uVar3 * 8;
        puVar1 = auStack_ce + 0xb;
        uVar3 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar3) =
             *(uint *)(puVar1 + -uVar3) & 0xffffffffU >> (uVar3 + 1) * 8 | 2 << (3 - uVar3) * 8;
        iVar8 = rand();
        puVar1 = auStack_ce + 0xc;
        uVar3 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar3) =
             *(uint *)(puVar1 + -uVar3) & -1 << (4 - uVar3) * 8 |
             (uint)(iVar8 % 0x93a80) >> uVar3 * 8;
        puVar1 = auStack_ce + 0xf;
        uVar3 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar3) =
             *(uint *)(puVar1 + -uVar3) & 0xffffffffU >> (uVar3 + 1) * 8 |
             iVar8 % 0x93a80 << (3 - uVar3) * 8;
        uVar3 = rand();
        if (l_wserv_profile == 0) {
          trap(7);
        }
        snprintf(auStack_ce + 0x10,0x41,"psk%d",uVar3 % l_wserv_profile);
      }
      else if (uVar3 == 2) {
        iVar8 = rand();
        uVar11 = iVar8 % 4;
        puVar1 = auStack_ce + 4;
        uVar3 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar3) =
             *(uint *)(puVar1 + -uVar3) & -1 << (4 - uVar3) * 8 | uVar11 >> uVar3 * 8;
        puVar1 = auStack_ce + 7;
        uVar3 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar3) =
             *(uint *)(puVar1 + -uVar3) & 0xffffffffU >> (uVar3 + 1) * 8 | uVar11 << (3 - uVar3) * 8
        ;
        if (uVar11 == 0) {
          puVar1 = auStack_ce + 4;
          uVar3 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar3) =
               *(uint *)(puVar1 + -uVar3) & -1 << (4 - uVar3) * 8 | 3U >> uVar3 * 8;
          puVar1 = auStack_ce + 7;
          uVar3 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar3) =
               *(uint *)(puVar1 + -uVar3) & 0xffffffffU >> (uVar3 + 1) * 8 | 3 << (3 - uVar3) * 8;
        }
        iVar8 = rand();
        puVar1 = auStack_ce + 8;
        uVar3 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar3) =
             *(uint *)(puVar1 + -uVar3) & -1 << (4 - uVar3) * 8 | (uint)(iVar8 % 3) >> uVar3 * 8;
        puVar1 = auStack_ce + 0xb;
        uVar3 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar3) =
             *(uint *)(puVar1 + -uVar3) & 0xffffffffU >> (uVar3 + 1) * 8 |
             iVar8 % 3 << (3 - uVar3) * 8;
        iVar8 = rand();
        puVar1 = auStack_ce + 0xc;
        uVar3 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar3) =
             *(uint *)(puVar1 + -uVar3) & -1 << (4 - uVar3) * 8 |
             (uint)(iVar8 % 0x93a80) >> uVar3 * 8;
        puVar1 = auStack_ce + 0xf;
        uVar3 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar3) =
             *(uint *)(puVar1 + -uVar3) & 0xffffffffU >> (uVar3 + 1) * 8 |
             iVar8 % 0x93a80 << (3 - uVar3) * 8;
        strcpy(auStack_ce + 0x10,"10.10.10.1");
        uVar3 = (uint)auStack_96 & 3;
        puVar2 = (uint *)(auStack_96 + -uVar3);
        *puVar2 = *puVar2 & -1 << (4 - uVar3) * 8 | 0x714U >> uVar3 * 8;
        puVar1 = auStack_96 + 3;
        uVar3 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar3) =
             *(uint *)(puVar1 + -uVar3) & 0xffffffffU >> (uVar3 + 1) * 8 | 0x714 << (3 - uVar3) * 8;
        strcpy(acStack_8e,"radius_pwd");
      }
      else {
        memset(auStack_ce + 4,0,0x80);
      }
      wserv_db_entry_add(auStack_238);
    }
    for (; iVar8 < iVar10; iVar8 = iVar8 + 1) {
      iVar9 = rand();
      iVar5 = apmngr_db_get_ap_max();
      uVar3 = rand();
      uVar11 = rdmngr_profile_get_max_rd_per_ap();
      if (iVar5 == 0) {
        trap(7);
      }
      if (uVar11 == 0) {
        trap(7);
      }
      iVar9 = (iVar9 % iVar5) * 0x10 + uVar3 % uVar11;
      uVar3 = 0;
      _wserv_rd_add(iVar9);
      while (uVar11 = rdmngr_profile_get_max_wlan_per_rd(), uVar3 < uVar11) {
        uVar3 = uVar3 + 1;
        uVar11 = rand();
        if (l_wserv_profile == 0) {
          trap(7);
        }
        uVar11 = uVar11 % l_wserv_profile;
        iVar5 = rand();
        wserv_db_rd_bind(iVar9,uVar11,iVar5 % 0x1000,0);
      }
    }
    while (2 < DAT_007cbf00) {
      iVar10 = rand();
      iVar9 = apmngr_db_get_ap_max();
      uVar3 = rand();
      uVar11 = rdmngr_profile_get_max_rd_per_ap();
      if (iVar9 == 0) {
        trap(7);
      }
      if (uVar11 == 0) {
        trap(7);
      }
      _wserv_rd_del((iVar10 % iVar9) * 0x10 + uVar3 % uVar11);
    }
    uVar3 = 0;
    while( true ) {
      iVar10 = apmngr_db_get_ap_max();
      iVar9 = apmngr_db_get_template_max();
      iVar8 = apmngr_db_get_sensor_max();
      iVar5 = rdmngr_profile_get_max_rd_per_ap();
      if ((uint)((iVar10 + iVar9 + iVar8) * iVar5) <= uVar3) break;
      if (*(char *)(DAT_007cbf04 + uVar3 * 0xc) == '\0') {
        uVar3 = uVar3 + 1;
      }
      else {
        iVar10 = 3;
        do {
          uVar11 = rand();
          uVar6 = rdmngr_profile_get_max_wlan_per_rd();
          if (uVar6 == 0) {
            trap(7);
          }
          iVar9 = DAT_007cbf04 + uVar3 * 0xc;
          pcVar7 = (char *)(*(int *)(iVar9 + 8) + (uVar11 % uVar6) * 6);
          if (*pcVar7 != '\0') {
            wserv_db_rd_unbind(*(undefined4 *)(iVar9 + 4),(int)*(short *)(pcVar7 + 2),0);
          }
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
        uVar3 = uVar3 + 1;
      }
    }
    wserv_rd_print_all();
    uVar3 = 0;
    while( true ) {
      iVar10 = apmngr_db_get_ap_max();
      iVar9 = apmngr_db_get_template_max();
      iVar8 = apmngr_db_get_sensor_max();
      iVar5 = rdmngr_profile_get_max_rd_per_ap();
      if ((uint)((iVar10 + iVar9 + iVar8) * iVar5) <= uVar3) break;
      uVar11 = 0;
      if (*(char *)(DAT_007cbf04 + uVar3 * 0xc) == '\0') {
        uVar3 = uVar3 + 1;
      }
      else {
        while (uVar6 = rdmngr_profile_get_max_wlan_per_rd(), uVar11 < uVar6) {
          pcVar7 = (char *)(*(int *)(DAT_007cbf04 + uVar3 * 0xc + 8) + uVar11 * 6);
          if (*pcVar7 == '\0') {
            uVar11 = uVar11 + 1;
          }
          else {
            iVar9 = *(short *)(pcVar7 + 2) * 0x21c;
            iVar10 = DAT_007cbefc + iVar9;
            if (*(int *)(iVar10 + 0xc) == 0) {
              uVar11 = uVar11 + 1;
            }
            else {
              uVar11 = uVar11 + 1;
              _wserv_print_entry(iVar10 + 0x10);
              printf("rd_hash   = ");
              FUN_00408570(*(undefined4 *)(DAT_007cbefc + iVar9 + 0x218),_print_rd_wlan_hash,0);
              putchar(10);
            }
          }
        }
        uVar3 = uVar3 + 1;
      }
    }
    wserv_db_uninit();
    FUN_00407df0(iStack_30);
    uVar4 = 0;
  }
  return uVar4;
}

