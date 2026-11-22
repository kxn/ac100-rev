// func close_snapshot_file @ 0058f8a4 size=64

void close_snapshot_file(void)

{
  if (*(FILE **)(g_write_snapshot_data + 0x1c) != (FILE *)0x0) {
    fclose(*(FILE **)(g_write_snapshot_data + 0x1c));
    *(undefined4 *)(g_write_snapshot_data + 0x1c) = 0;
  }
  return;
}

