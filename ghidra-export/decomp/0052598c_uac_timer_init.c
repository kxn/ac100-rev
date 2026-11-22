// func uac_timer_init @ 0052598c size=900

undefined4 uac_timer_init(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  char *__format;
  char *pcVar4;
  int iVar5;
  
  puVar1 = PTR_DAT_007591ac;
  uVar2 = 0;
  if (DAT_007c5418 == 0) {
    if (param_1 - 2 < 0x13) {
      *(uint *)(PTR_DAT_007591ac + 0x2064) = param_1;
      DAT_007c5400 = uac_id_new((1 << (param_1 & 0x1f)) + -1,param_2,param_3,param_1);
      if (DAT_007c5400 == 0) {
        uVar2 = 0xac;
        __format = "[WHEEL_TIMER_ERROR]%s()/%d Failed to alloc mem for id allocator.\n";
        pcVar4 = "__tvec_base_init";
      }
      else {
        DAT_007c53e4 = (void *)uac_mem_calloc_my(1 << (*(uint *)(puVar1 + 0x2064) & 0x1f),0x6c,0xb0)
        ;
        if (DAT_007c53e4 == (void *)0x0) {
          uVar2 = 0xb3;
          __format = "[WHEEL_TIMER_ERROR]%s()/%d Failed to alloc mem for timers array.\n";
          pcVar4 = "__tvec_base_init";
        }
        else {
          memset(DAT_007c53e4,0,0x6c << (*(uint *)(puVar1 + 0x2064) & 0x1f));
          sigemptyset((sigset_t *)&DAT_007c5404);
          sigaddset((sigset_t *)&DAT_007c5404,0xe);
          g_wheel_timer_base = uac_mutex_create("wheel_timer_db_mutex",1);
          DAT_007c3bd8 = uac_mutex_create("wheel_timer_msg_mutex",0);
          DAT_007c3bdc = uac_cond_create("wheel_timer_msg_cond");
          if (((g_wheel_timer_base == 0) || (DAT_007c3bd8 == 0)) || (DAT_007c3bdc == 0)) {
            uVar2 = 0xc1;
            __format = "[WHEEL_TIMER_ERROR]%s()/%d Create apmngr db mutex failed.\n";
            pcVar4 = "__tvec_base_init";
          }
          else {
            iVar5 = 0;
            DAT_007c3be0 = 0;
            uac_list_init(&DAT_007c53f4);
            do {
              iVar3 = iVar5 * 0xc;
              iVar5 = iVar5 + 1;
              uac_list_init(&DAT_007c3be4 + iVar3);
            } while (iVar5 != 0x100);
            iVar5 = 0;
            do {
              iVar3 = iVar5 * 0xc;
              iVar5 = iVar5 + 1;
              uac_list_init(&DAT_007c47e4 + iVar3);
              uac_list_init(&DAT_007c4ae4 + iVar3);
              uac_list_init(&DAT_007c4de4 + iVar3);
              uac_list_init(&DAT_007c50e4 + iVar3);
            } while (iVar5 != 0x40);
            iVar5 = uac_thread_create(&g_wheel_timer_tick_pid,"wheeltimertickd",__tick_thread,0);
            if (iVar5 == 0) {
              iVar5 = uac_thread_create(&g_wheel_timer_work_pid,"wheeltimerworkd",__work_thread,0);
              if (iVar5 == 0) {
                DAT_007c5418 = 1;
                g_wheel_timer_inited = 1;
                return 0;
              }
              uVar2 = 0x2f4;
              __format = "[WHEEL_TIMER_ERROR]%s()/%d Failed to create thread of timer.\n\n";
              pcVar4 = "__base_init";
            }
            else {
              uVar2 = 0x2ed;
              __format = "[WHEEL_TIMER_ERROR]%s()/%d Failed to create thread of timer.\n\n";
              pcVar4 = "__base_init";
            }
          }
        }
      }
      printf(__format,pcVar4,uVar2);
      FUN_00524fdc();
      printf("[WHEEL_TIMER_ERROR]%s()/%d Failed to init timer.\n\n","uac_timer_init",0x37b);
      uVar2 = 0xffffffff;
    }
    else {
      printf("[WHEEL_TIMER_ERROR]%s()/%d Range error: g_wheel_timer_id_len=%d, should be range from 2 to %d\n"
             ,"uac_timer_init",0x373,param_1,0x14);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

