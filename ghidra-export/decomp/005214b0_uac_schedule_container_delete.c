// func uac_schedule_container_delete @ 005214b0 size=236

undefined4 uac_schedule_container_delete(int param_1,int param_2)

{
  int iVar1;
  char *__s;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uac_mutex_take(*(undefined4 *)(param_1 + 0x30),0xffffffff);
    if (*(int *)(param_1 + 100) == 0) {
      __s = 
      "The schedule container does not support hash,can\'t call uac_schedule_container_delete!";
    }
    else {
      iVar1 = uac_hash_get(*(undefined4 *)(param_1 + 0x68),param_2);
      if (iVar1 != 0) {
        uac_hash_remove(*(undefined4 *)(param_1 + 0x68),iVar1);
        uac_list_remove(iVar1);
        uac_mutex_give(*(undefined4 *)(param_1 + 0x30));
        return 0;
      }
      __s = "Does not exsist, delete failed!";
    }
    puts(__s);
    uac_mutex_give(*(undefined4 *)(param_1 + 0x30));
  }
  return 0xffffffff;
}

