// func _apdb_unknown_ap_record @ 0060edbc size=208

undefined4 _apdb_unknown_ap_record(void)

{
  FILE *__s;
  size_t sVar1;
  char *__format;
  undefined4 uVar2;
  
  __s = fopen("/tmp/unknown_ap_flag","w+");
  if (__s == (FILE *)0x0) {
    if (apdb_err_switch != 0) {
      __format = "[APDB_ERROR]%s()/line %d : Failed to record unkown ap.\n";
      uVar2 = 0x69;
      goto LAB_0060ee6c;
    }
  }
  else {
    sVar1 = fwrite("1",1,1,__s);
    if (sVar1 == 1) {
      fclose(__s);
      return 0;
    }
    fclose(__s);
    if (apdb_err_switch != 0) {
      __format = "[APDB_ERROR]%s()/line %d : Failed to write unknown file.\n";
      uVar2 = 0x6f;
LAB_0060ee6c:
      printf(__format,"_apdb_unknown_ap_record",uVar2);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

