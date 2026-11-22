// func uac_md5_timer_init @ 0051d400 size=832

undefined4 uac_md5_timer_init(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  char *__format;
  char *pcVar4;
  int iVar5;
  
  puVar1 = PTR_DAT_007591ac;
  uVar2 = 0;
  if (DAT_00783b18 == 0) {
    if (param_1 - 2 < 0x13) {
      *(uint *)(PTR_DAT_007591ac + 0x2044) = param_1;
      DAT_00783b00 = uac_id_new((1 << (param_1 & 0x1f)) + -1,param_2,param_3,param_1);
      if (DAT_00783b00 == 0) {
        uVar2 = 0xaa;
        __format = "[WHEEL_MD5_TIMER_ERROR]%s()/%d Failed to alloc mem for id allocator.\n";
        pcVar4 = "__tvec_base_init";
      }
      else {
        DAT_00783ae4 = (void *)uac_mem_calloc_my(1 << (*(uint *)(puVar1 + 0x2044) & 0x1f),0x6c,0xae)
        ;
        if (DAT_00783ae4 == (void *)0x0) {
          uVar2 = 0xb1;
          __format = "[WHEEL_MD5_TIMER_ERROR]%s()/%d Failed to alloc mem for timers array.\n";
          pcVar4 = "__tvec_base_init";
        }
        else {
          memset(DAT_00783ae4,0,0x6c << (*(uint *)(puVar1 + 0x2044) & 0x1f));
          sigemptyset((sigset_t *)&DAT_00783b04);
          sigaddset((sigset_t *)&DAT_00783b04,0xe);
          g_wheel_md5_timer_base = uac_mutex_create("wheel_md5_timer_db_mutex",1);
          DAT_007822d8 = uac_mutex_create("wheel_md5_timer_msg_mutex",0);
          DAT_007822dc = uac_cond_create("wheel_md5_timer_msg_cond");
          if (((g_wheel_md5_timer_base == 0) || (DAT_007822d8 == 0)) || (DAT_007822dc == 0)) {
            uVar2 = 0xbf;
            __format = "[WHEEL_MD5_TIMER_ERROR]%s()/%d Create apmngr db mutex failed.\n";
            pcVar4 = "__tvec_base_init";
          }
          else {
            iVar5 = 0;
            DAT_007822e0 = 0;
            uac_list_init(&DAT_00783af4);
            do {
              iVar3 = iVar5 * 0xc;
              iVar5 = iVar5 + 1;
              uac_list_init(&DAT_007822e4 + iVar3);
            } while (iVar5 != 0x100);
            iVar5 = 0;
            do {
              iVar3 = iVar5 * 0xc;
              iVar5 = iVar5 + 1;
              uac_list_init(&DAT_00782ee4 + iVar3);
              uac_list_init(&DAT_007831e4 + iVar3);
              uac_list_init(&DAT_007834e4 + iVar3);
              uac_list_init(&DAT_007837e4 + iVar3);
            } while (iVar5 != 0x40);
            iVar5 = uac_thread_create(&g_wheel_md5_timer_work_pid,"wheelMD5timerworkd",__work_thread
                                      ,0);
            if (iVar5 == 0) {
              DAT_00783b18 = 1;
              g_wheel_md5_timer_inited = 1;
              return 0;
            }
            uVar2 = 0x2cf;
            __format = "[WHEEL_MD5_TIMER_ERROR]%s()/%d Failed to create thread of timer.\n\n";
            pcVar4 = "__base_init";
          }
        }
      }
      printf(__format,pcVar4,uVar2);
      FUN_0051ca50();
      printf("[WHEEL_MD5_TIMER_ERROR]%s()/%d Failed to init timer.\n\n","uac_md5_timer_init",0x356);
      uVar2 = 0xffffffff;
    }
    else {
      printf("[WHEEL_MD5_TIMER_ERROR]%s()/%d Range error: g_wheel_md5_timer_id_len=%d, should be range from 2 to %d\n"
             ,"uac_md5_timer_init",0x34e,param_1,0x14);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

