#pragma once

#include <QtGui>

#include <Windows.h>
#include <Psapi.h>
#include <winternl.h>
#include <detours.h>
#include <random>

#pragma comment(lib, "Psapi")
#pragma comment(lib, "detours")

#include <boost\thread.hpp>

#include "Addresses.h"

#include "CFunctionManager.h"
#include "CPackets.h"