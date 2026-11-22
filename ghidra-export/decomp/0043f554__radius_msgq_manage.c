// func _radius_msgq_manage @ 0043f554 size=4000

/* WARNING: Type propagation algorithm not settling */

int _radius_msgq_manage(int param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *__s;
  uint uVar3;
  undefined4 uVar4;
  int extraout_v1;
  undefined1 *puVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 uVar8;
  int iVar9;
  void *pvVar10;
  code *pcVar11;
  int iVar12;
  undefined8 uVar13;
  undefined1 local_7c8 [4];
  int local_7c4 [5];
  epoll_event local_7b0;
  undefined1 auStack_7a0 [40];
  undefined1 auStack_778 [352];
  undefined4 local_618;
  undefined4 local_614;
  int local_5f8;
  undefined1 auStack_5f4 [255];
  undefined1 auStack_4f5 [121];
  undefined1 auStack_47c [104];
  undefined1 auStack_414 [24];
  int local_3fc;
  undefined4 local_3f4;
  short local_3f0;
  undefined1 auStack_3e8 [524];
  undefined1 auStack_1dc [101];
  undefined1 auStack_177 [101];
  undefined1 auStack_112 [16];
  undefined1 auStack_102 [65];
  undefined1 auStack_c1 [6];
  undefined1 auStack_bb [7];
  undefined1 auStack_b4 [20];
  undefined1 auStack_a0 [24];
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined2 local_74;
  undefined1 local_72;
  undefined1 local_71;
  undefined1 auStack_70 [32];
  undefined1 auStack_50 [16];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  iVar12 = 0;
  iVar9 = 0;
  local_7c4[1] = 0;
  local_7c8[0] = 0;
LAB_0043f5b8:
  do {
    iVar2 = g_max_session;
    if (g_max_session < 0) {
      iVar2 = g_max_session + 7;
    }
    if (iVar2 >> 3 <= iVar12) {
      iVar12 = param_2[1];
      goto LAB_0044021c;
    }
    memset(&local_5f8,0,0x5d0);
    iVar2 = uac_msgQ_receive(*param_2,&local_5f8,0x5d0,0,local_7c4 + 1);
    if (iVar2 == -1) {
      iVar9 = -1;
      iVar12 = param_2[1];
LAB_0044021c:
      read(iVar12,local_7c8,1);
      return iVar9;
    }
    memset((void *)param_2[4],0,0x7fe);
    if (local_5f8 != 3) {
      if (local_5f8 == 4) {
        if (radius_debug_switch != 0) {
          printf("[RADIUS_DEBUG]%s()/%d update radius auth message\n","_radius_msgq_manage",0xa1f);
        }
        local_7c4[0] = -1;
        iVar9 = -1;
        __s = (undefined4 *)uac_mem_malloc_my(0x648,0x955);
        if (__s != (undefined4 *)0x0) {
          memset(__s,0,0x648);
          __s[0x17f] = 3;
          *(undefined1 *)((int)__s + 0x62a) = 4;
          memcpy(__s + 0x164,auStack_a0,0x14);
          memcpy((void *)((int)__s + 0x54d),auStack_bb,6);
          memcpy((void *)((int)__s + 0x547),auStack_c1,6);
          __s[0x17c] = local_80;
          memcpy(__s + 0x15f,auStack_b4,0x14);
          memcpy(__s + 1,auStack_5f4,0xff);
          __s[0x81] = local_3f4;
          memcpy(__s + 0x79,auStack_414,0x14);
          memcpy(__s + 0x5f,auStack_47c,100);
          memcpy((void *)((int)__s + 0x103),auStack_4f5,0x78);
          *__s = __s + 1;
          memcpy(__s + 0x107,auStack_1dc,100);
          __s[0x15a] = local_88;
          __s[0x15b] = local_84;
          *(undefined1 *)((int)__s + 0x62b) = 1;
          __s[0x180] = local_7c;
          __s[0x18d] = local_3c;
          __s[0x18c] = local_40;
          __s[399] = local_34;
          __s[0x18e] = local_38;
          __s[400] = local_30;
          memcpy(__s + 0x182,auStack_70,0x20);
          iVar9 = wportal_get_mode();
          if ((iVar9 == 2) && ((*(byte *)(__s + 0x18b) & 4) == 0)) {
            puVar5 = auStack_50;
            pcVar11 = memcpy;
          }
          else {
            pcVar11 = memset;
            puVar5 = (undefined1 *)0x0;
          }
          (*pcVar11)((int)__s + 0x553,puVar5,0x10);
          iVar9 = _radius_send_to_server(param_2 + 8,__s,param_2[4],local_7c4);
          _radius_send_result_to_ngx(__s,__s + 0x16c);
LAB_0043fc84:
          uac_mem_free_my(__s);
LAB_0043fa28:
          iVar12 = iVar12 + 1;
          goto LAB_0043f5b8;
        }
      }
      else if (local_5f8 == 1) {
        if (radius_debug_switch != 0) {
          printf("[RADIUS_DEBUG]%s()/%d Get radius auth message\n","_radius_msgq_manage",0xa1a);
        }
        local_7c4[0] = -1;
        uac_mutex_take(param_2[3],0xffffffff);
        iVar2 = uac_list_first(param_2[5]);
        if (iVar2 == 0) {
          if (radius_debug_switch != 0) {
            uVar8 = 0x9a0;
            pcVar7 = "_radius_manage";
            goto LAB_004404cc;
          }
          goto LAB_00440448;
        }
        pvVar10 = (void *)(iVar2 + -0x570);
        uac_list_remove(iVar2);
        uac_mutex_give(param_2[3]);
        memcpy((void *)(iVar2 + -0x56c),auStack_5f4,0x20c);
        memcpy((void *)(iVar2 + -0x360),auStack_3e8,0x20c);
        *(undefined4 *)(iVar2 + 0x7c) = 0;
        *(void **)(iVar2 + -0x570) = (void *)(iVar2 + -0x56c);
        memset((void *)(iVar2 + 0x34),0,8);
        memcpy((void *)(iVar2 + -0x6a),auStack_102,0x40);
        *(char *)(iVar2 + 0xb9) = (char)local_74;
        memcpy((void *)(iVar2 + -0x29),auStack_c1,6);
        memcpy((void *)(iVar2 + -0x23),auStack_bb,6);
        memcpy((void *)(iVar2 + 0x20),auStack_a0,0x14);
        memcpy((void *)(iVar2 + 0xc),auStack_b4,0x14);
        *(undefined4 *)(iVar2 + 0x78) = 0xffffffff;
        *(undefined4 *)(iVar2 + 0x94) = local_78;
        memcpy((void *)(iVar2 + -0x154),auStack_1dc,0x65);
        memcpy((void *)(iVar2 + -0xef),auStack_177,0x65);
        *(undefined1 *)(iVar2 + 0xba) = 1;
        *(undefined4 *)(iVar2 + 0x68) = 0;
        *(undefined4 *)(iVar2 + 0x6c) = 0;
        *(undefined4 *)(iVar2 + 0x8c) = 0;
        memcpy((void *)(iVar2 + -0x7a),auStack_112,0x10);
        *(undefined4 *)(iVar2 + 0x88) = 0;
        *(undefined4 *)(iVar2 + 0x84) = 0;
        *(undefined1 *)(iVar2 + 0xb8) = local_72;
        *(undefined4 *)(iVar2 + 0x80) = 0;
        memset((void *)(iVar2 + -0x8a),0,0x10);
        *(undefined1 *)(iVar2 + 0xbb) = 0;
        *(undefined4 *)(iVar2 + 0x90) = 0;
        *(undefined4 *)(iVar2 + 0x70) = 0;
        *(undefined4 *)(iVar2 + 0x74) = 0;
        *(undefined1 *)(iVar2 + 0xbc) = local_71;
        memcpy((void *)(iVar2 + 0x98),auStack_70,0x20);
        iVar9 = wportal_get_mode();
        if ((iVar9 == 2) && ((*(byte *)(iVar2 + 0xbc) & 4) == 0)) {
          puVar5 = auStack_50;
          pcVar11 = memcpy;
        }
        else {
          pcVar11 = memset;
          puVar5 = (undefined1 *)0x0;
        }
        (*pcVar11)(iVar2 + -0x1d,puVar5,0x10);
        uac_mutex_take(g_sess_id_mutex,0xffffffff);
        puVar1 = PTR_DAT_007591ac;
        uVar6 = *(uint *)(PTR_DAT_007591ac + 0x129c);
        iVar9 = *(int *)(PTR_DAT_007591ac + 0x1298);
        uVar3 = uVar6 + 1;
        *(uint *)(iVar2 + -4) = uVar3;
        iVar9 = (uint)(uVar3 < uVar6) + iVar9;
        *(uint *)(puVar1 + 0x129c) = uVar3;
        *(int *)(iVar2 + -8) = iVar9;
        *(int *)(puVar1 + 0x1298) = iVar9;
        uac_mutex_give(g_sess_id_mutex);
        iVar9 = _radius_send_to_server(0,pvVar10,param_2[4],local_7c4);
        if (iVar9 == 0) {
          if (local_7c4[0] != -1) {
            *(int *)(iVar2 + 0x78) = local_7c4[0];
          }
        }
        else if (local_7c4[0] != -1) {
          if (radius_debug_switch != 0) {
            uVar8 = 0x9e0;
            pcVar7 = "_radius_manage";
            goto LAB_00440408;
          }
          goto LAB_0043fa4c;
        }
LAB_0043f924:
        *(int *)(iVar2 + 0x84) = iVar9;
        uac_mutex_take(param_2[3],0xffffffff);
        uac_list_insert_last(param_2[6],iVar2);
        uac_mutex_give(param_2[3]);
        if ((pvVar10 != (void *)0x0) && (*(int *)((int)pvVar10 + 0x5e8) != -1)) {
          if (radius_debug_switch != 0) {
            printf("[RADIUS_DEBUG]%s()/%d Add to epoll event: %d\n","_radius_msgq_manage",0xa2d);
          }
          local_7b0._4_4_ = 0;
          local_7b0.data.u64._4_4_ = 0;
          local_7b0.events = 1;
          local_7b0.data._0_4_ = pvVar10;
          iVar2 = epoll_ctl(param_1,1,*(int *)((int)pvVar10 + 0x5e8),&local_7b0);
          if (iVar2 < 0) {
            if (radius_debug_switch != 0) {
              printf("[RADIUS_DEBUG]%s()/%d Add epoll error\n\n","_radius_msgq_manage",0xa33);
            }
            uac_mutex_take(param_2[3],0xffffffff);
            uac_list_remove((int)pvVar10 + 0x570);
            uac_list_insert_first(param_2[5],(int)pvVar10 + 0x570);
            close(*(int *)((int)pvVar10 + 0x5e8));
            *(undefined4 *)((int)pvVar10 + 0x5e8) = 0xffffffff;
            uac_mutex_give(param_2[3]);
            goto LAB_0043fa28;
          }
        }
      }
LAB_0043f658:
      iVar12 = iVar12 + 1;
      goto LAB_0043f5b8;
    }
    if (radius_debug_switch != 0) {
      printf("[RADIUS_DEBUG]%s()/%d stop radius auth message\n","_radius_msgq_manage",0xa23);
    }
    local_7c4[0] = -1;
    memset(auStack_778,0,0x180);
    memset(auStack_7a0,0,0x28);
    if (local_3f0 == 0) {
      iVar9 = -1;
      __s = (undefined4 *)uac_mem_malloc_my(0x648,0x8fc);
      if (__s != (undefined4 *)0x0) {
        memset(__s,0,0x648);
        __s[0x17f] = 2;
        *(undefined1 *)((int)__s + 0x62a) = 4;
        puVar5 = (undefined1 *)((int)__s + 0x547);
        memcpy(__s + 0x164,auStack_a0,0x14);
        memcpy((void *)((int)__s + 0x54d),auStack_bb,6);
        memcpy(puVar5,auStack_c1,6);
        __s[0x17c] = local_80;
        memcpy(__s + 0x15f,auStack_b4,0x14);
        memcpy(__s + 1,auStack_5f4,0xff);
        __s[0x81] = local_3f4;
        memcpy(__s + 0x79,auStack_414,0x14);
        memcpy(__s + 0x5f,auStack_47c,100);
        memcpy((void *)((int)__s + 0x103),auStack_4f5,0x78);
        *__s = __s + 1;
        memcpy(__s + 0x107,auStack_1dc,100);
        if (((*(char *)((int)__s + 0x547) == '\0') && (__s[0x152] == 0)) &&
           (*(char *)(__s + 0x153) == '\0')) {
          memset(auStack_7a0,0,0x28);
          uac_ipaddr_convert_binary2str
                    (__s[0x15f],__s[0x160],__s[0x161],__s[0x162],__s[0x163],auStack_7a0,0x28,"---");
          if (radius_debug_switch != 0) {
            printf("[RADIUS_DEBUG]%s()/%d get db aut entry by ip:%s\n","_radius_acct_stop",0x919,
                   auStack_7a0);
          }
          puVar5 = auStack_7a0;
          pcVar11 = wportal_db_aut_get_by_ip;
        }
        else {
          pcVar11 = wportal_db_aut_get;
        }
        iVar9 = (*pcVar11)(puVar5,auStack_778);
        uVar8 = local_88;
        uVar4 = local_84;
        if (iVar9 == 0) {
          uVar8 = local_618;
          uVar4 = local_614;
        }
        __s[0x15a] = uVar8;
        __s[0x15b] = uVar4;
        *(undefined1 *)((int)__s + 0x62b) = 1;
        *(short *)(__s + 0x82) = local_3f0;
        __s[0x7f] = local_3fc;
        __s[0x180] = local_7c;
        memcpy(__s + 0x182,auStack_70,0x20);
        __s[0x18d] = local_3c;
        __s[0x18c] = local_40;
        __s[399] = local_34;
        __s[0x18e] = local_38;
        iVar9 = wportal_get_mode();
        if ((iVar9 == 2) && ((*(byte *)(__s + 0x18b) & 4) == 0)) {
          puVar5 = auStack_50;
          pcVar11 = memcpy;
        }
        else {
          pcVar11 = memset;
          puVar5 = (undefined1 *)0x0;
        }
        (*pcVar11)((int)__s + 0x553,puVar5,0x10);
        iVar9 = _radius_send_to_server(param_2 + 8,__s,param_2[4],local_7c4);
        goto LAB_0043fc84;
      }
      goto LAB_0043f658;
    }
    uac_mutex_take(param_2[3],0xffffffff);
    iVar2 = uac_list_first(param_2[5]);
    if (iVar2 != 0) {
      puVar5 = (undefined1 *)(iVar2 + -0x29);
      uac_list_remove(iVar2);
      pvVar10 = (void *)(iVar2 + -0x570);
      uac_mutex_give(param_2[3]);
      *(undefined4 *)(iVar2 + 0x8c) = 2;
      *(undefined1 *)(iVar2 + 0xba) = 4;
      memcpy((void *)(iVar2 + 0x20),auStack_a0,0x14);
      memcpy((void *)(iVar2 + -0x23),auStack_bb,6);
      memcpy(puVar5,auStack_c1,6);
      *(undefined4 *)(iVar2 + 0x80) = local_80;
      memcpy((void *)(iVar2 + 0xc),auStack_b4,0x14);
      memcpy((void *)(iVar2 + -0x56c),auStack_5f4,0xff);
      *(undefined4 *)(iVar2 + -0x36c) = local_3f4;
      memcpy((void *)(iVar2 + -0x38c),auStack_414,0x14);
      memcpy((void *)(iVar2 + -0x3f4),auStack_47c,100);
      memcpy((void *)(iVar2 + -0x46d),auStack_4f5,0x78);
      *(void **)(iVar2 + -0x570) = (void *)(iVar2 + -0x56c);
      memcpy((void *)(iVar2 + -0x154),auStack_1dc,100);
      if (((*(char *)(iVar2 + -0x29) == '\0') && (*(int *)(iVar2 + -0x28) == 0)) &&
         (*(char *)(iVar2 + -0x24) == '\0')) {
        memset(auStack_7a0,0,0x28);
        uac_ipaddr_convert_binary2str
                  (*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 0x10),
                   *(undefined4 *)(iVar2 + 0x14),*(undefined4 *)(iVar2 + 0x18),
                   *(undefined4 *)(iVar2 + 0x1c),auStack_7a0,0x28,"---");
        if (radius_debug_switch != 0) {
          printf("[RADIUS_DEBUG]%s()/%d get db aut entry by ip:%s\n","_radius_acct_stop",0x8c3,
                 auStack_7a0);
        }
        puVar5 = auStack_7a0;
        pcVar11 = wportal_db_aut_get_by_ip;
      }
      else {
        pcVar11 = wportal_db_aut_get;
      }
      iVar9 = (*pcVar11)(puVar5,auStack_778);
      uVar8 = local_88;
      uVar4 = local_84;
      if (iVar9 == 0) {
        uVar8 = local_618;
        uVar4 = local_614;
      }
      *(undefined4 *)(iVar2 + -8) = uVar8;
      *(undefined4 *)(iVar2 + -4) = uVar4;
      *(undefined1 *)(iVar2 + 0xbb) = 1;
      *(short *)(iVar2 + -0x368) = local_3f0;
      *(int *)(iVar2 + -0x374) = local_3fc;
      *(undefined4 *)(iVar2 + 0x90) = local_7c;
      memcpy((void *)(iVar2 + 0x98),auStack_70,0x20);
      *(undefined4 *)(iVar2 + 0xc4) = local_3c;
      *(undefined4 *)(iVar2 + 0xc0) = local_40;
      *(undefined4 *)(iVar2 + 0xcc) = local_34;
      *(undefined4 *)(iVar2 + 200) = local_38;
      iVar9 = wportal_get_mode();
      if ((iVar9 == 2) && (puVar5 = auStack_50, (*(byte *)(iVar2 + 0xbc) & 4) == 0)) {
        pcVar11 = memcpy;
      }
      else {
        pcVar11 = memset;
        puVar5 = (undefined1 *)0x0;
      }
      (*pcVar11)(iVar2 + -0x1d,puVar5,0x10);
      local_7c4[2] = 0;
      local_7c4[3] = 0;
      uVar13 = uac_time_usecs();
      __udivdi3((int)((ulonglong)uVar13 >> 0x20),(int)uVar13,0,1000000);
      local_7c4[2] = local_3fc + extraout_v1;
      *(int *)(iVar2 + 0x34) = local_7c4[2];
      *(int *)(iVar2 + 0x38) = local_7c4[3];
      iVar9 = _radius_send_to_server(0,pvVar10,param_2[4],local_7c4);
      if ((iVar9 == 0) && (local_7c4[0] != -1)) {
        *(int *)(iVar2 + 0x78) = local_7c4[0];
      }
      else if (local_7c4[0] != -1) {
        if (radius_debug_switch != 0) {
          uVar8 = 0x8f0;
          pcVar7 = "_radius_acct_stop";
LAB_00440408:
          printf("[RADIUS_DEBUG]%s()/%d Send to radius server error\n",pcVar7,uVar8);
        }
LAB_0043fa4c:
        close(local_7c4[0]);
      }
      goto LAB_0043f924;
    }
    if (radius_debug_switch != 0) {
      uVar8 = 0x8a2;
      pcVar7 = "_radius_acct_stop";
LAB_004404cc:
      printf("[RADIUS_DEBUG]%s()/%d No free node to handle radius\n\n",pcVar7,uVar8);
    }
LAB_00440448:
    iVar9 = -1;
    iVar12 = iVar12 + 1;
    uac_mutex_give(param_2[3]);
  } while( true );
}

