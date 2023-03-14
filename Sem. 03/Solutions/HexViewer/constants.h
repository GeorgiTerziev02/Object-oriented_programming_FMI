#pragma once

// 10 kb
const int FILE_SIZE = 10 * 1024;
const int FILE_NAME_SIZE = 50;
const int INPUT_BUFFER_SIZE = 70;
const int COMMAND_SIZE = 20;
// MAX IS 255 - FF
const int HEX_SIZE = 3;

const char VIEW_COMMAND[] = "view";
const char CHANGE_COMMAND[] = "change";
const char REMOVE_COMMAND[] = "remove";
const char ADD_COMMAND[] = "add";
const char SAVE_COMMAND[] = "save";

const char OPEN_FILE_ERROR_MESSAGE[] = "Error opening the file";
const char SUCCESSFUL_OPERATION_MESSAGE[] = "Operation successfully executed!";
const char UNSUCCESSFUL_OPERATION_MESSAGE[] = "Operation didn't execute successfully!";

const int UPPERCASE_A_ASCII_CODE = 65;
const int UPPERCASE_F_ASCII_CODE = 70;
const int UPPERCASE_Z_ASCII_CODE = 90;
const int LOWERCASE_A_ASCII_CODE = 97;
const int LOWERCASE_Z_ASCII_CODE = 122;
