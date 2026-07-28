#include <CorePCH.h>

// Must come before any header pulling in DragDrop.hpp (e.g. via VCLCommon.h),
// whose "using namespace Dragdrop" makes Dragdrop::IDataObject ambiguous with
// the global COM IDataObject that MSHTML/mshtmhst.h reference unqualified.
#include <WebBrowserEx.hpp>

#include <Vcl.Consts.hpp>

#include <GUITools.h>
#include <HelpWin.h>
#include <PasTools.hpp>
#include <Tools.h>
#include <TextsWin.h>
#include <VCLCommon.h>
#include <WinConfiguration.h>
#include <WinInterface.h>
