// func _apdb_refresh_update_count @ 005fa390 size=100

void _apdb_refresh_update_count(int param_1)

{
  char *__format;
  char acStack_d0 [200];
  
  memset(acStack_d0,0,200);
  if (param_1 == 0) {
    __format = "echo 1 >> %s";
  }
  else {
    __format = "cat /dev/null > %s";
  }
  snprintf(acStack_d0,200,__format,"/tmp/nego_apdb_update_count~");
  system(acStack_d0);
  return;
}

