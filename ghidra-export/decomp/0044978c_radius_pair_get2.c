// func radius_pair_get2 @ 0044978c size=488

char * radius_pair_get2(undefined4 param_1,undefined4 param_2,size_t param_3,void *param_4)

{
  char *__src;
  char *__dest;
  size_t __n;
  undefined4 local_20 [3];
  
  local_20[0] = 0;
  __src = (char *)radius_dict_getattr_by_value();
  if (__src == (char *)0x0) {
    return (char *)0x0;
  }
  __dest = (char *)uac_mem_malloc_my(0x154,0x1d2);
  if (__dest == (char *)0x0) {
    return (char *)0x0;
  }
  pair_malloc = pair_malloc + 1;
  memset(__dest,0,0x154);
  strcpy(__dest,__src);
  *(undefined4 *)(__dest + 0x44) = *(undefined4 *)(__src + 0x44);
  *(undefined4 *)(__dest + 0x48) = *(undefined4 *)(__src + 0x48);
  switch(*(undefined4 *)(__src + 0x48)) {
  case 0:
    memcpy(__dest + 0x50,param_4,param_3);
    __dest[param_3 + 0x50] = '\0';
    *(size_t *)(__dest + 0x4c) = param_3;
    return __dest;
  case 1:
  case 2:
    if (param_3 == 4) {
      memcpy(local_20,param_4,4);
      *(undefined4 *)(__dest + 0x4c) = local_20[0];
      return __dest;
    }
    break;
  default:
    break;
  case 6:
    if (param_3 == 8) {
      __n = 8;
LAB_00449910:
      memcpy(__dest + 0x50,param_4,__n);
      return __dest;
    }
    break;
  case 7:
    if (param_3 == 0x10) {
      __n = 0x10;
      goto LAB_00449910;
    }
    break;
  case 8:
    if (param_3 - 2 < 0x11) {
      memcpy(__dest + 0x50,param_4,param_3);
      *(size_t *)(__dest + 0x4c) = param_3;
      return __dest;
    }
  }
  uac_mem_free_my(__dest);
  pair_free = pair_free + 1;
  return (char *)0x0;
}

