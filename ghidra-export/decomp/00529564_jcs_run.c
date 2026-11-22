// func jcs_run @ 00529564 size=408

undefined4 jcs_run(void)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined4 local_28 [3];
  
  local_28[0] = 0;
  if (is_run != 0) {
    return 0;
  }
  pcVar1 = (char *)uac_mem_malloc_my(0x80,0x1d7);
  if (pcVar1 == (char *)0x0) {
    if (jcs_err_switch == 0) {
      return 0xffffffff;
    }
    uVar2 = 0x1da;
  }
  else {
    sprintf(pcVar1,"%s.%s","/tmp/jcs.ui.srv",&pname);
    uac_thread_create(local_28,"jcs_ui",jcs_work_task,pcVar1);
    pcVar1 = (char *)uac_mem_malloc_my(0x80,0x1e1);
    if (pcVar1 != (char *)0x0) {
      sprintf(pcVar1,"%s.%s","/tmp/jcs.service.srv",&pname);
      uac_thread_create(local_28,"jcs_service",jcs_work_task,pcVar1);
      is_run = 1;
      return 0;
    }
    if (jcs_err_switch == 0) {
      return 0xffffffff;
    }
    uVar2 = 0x1e4;
  }
  printf("[JCS_ERR]%s()/%d Malloc jcs path failed.\n","jcs_run",uVar2);
  return 0xffffffff;
}

