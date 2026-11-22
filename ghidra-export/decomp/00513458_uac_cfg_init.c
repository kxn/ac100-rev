// func uac_cfg_init @ 00513458 size=316

undefined4 uac_cfg_init(int param_1)

{
  undefined4 uVar1;
  pthread_mutexattr_t pStack_18;
  undefined1 auStack_14 [4];
  undefined1 auStack_10 [8];
  
  uVar1 = 0;
  if ((DAT_00781a84 == 0) && (uVar1 = 0xffffffff, 0 < param_1)) {
    *(int *)(PTR_DAT_007591ac + 0x1dc4) = param_1;
    pthread_mutexattr_init(&pStack_18);
    pthread_mutexattr_settype(&pStack_18,1);
    pthread_mutex_init((pthread_mutex_t *)&cfg_mutex,&pStack_18);
    pthread_mutexattr_destroy(&pStack_18);
    uac_thread_key_create(&cfg_tsd_key,(__destr_function *)0x0);
    uac_list_init(&cfg_tsd_list);
    uac_list_init(&cfg_reg_list);
    uac_thread_create(auStack_10,"uac_cfg_set",_uac_cfg_chk_task,0);
    uac_thread_create(auStack_14,"uac_cfg_save",_uac_cfg_save_task,0);
    system(
          "ubus call cfg_save cp_cb_reg \'{\"copy_init\":\" /lib/functions/uac_cfg.sh  copy_init\", \"copy_action\":\" /lib/functions/uac_cfg.sh  copy_action\"}\' &> /dev/null"
          );
    DAT_00781a84 = 1;
    uVar1 = 0;
  }
  return uVar1;
}

