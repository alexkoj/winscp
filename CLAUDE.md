# WinSCP — Ghi chú cho Claude Code

Repo này là mã nguồn WinSCP (C++Builder/VCL, Windows), đã được build bằng
**RAD Studio 13 (BDS 37.0)**, bản **Community Edition**. Fork này có tùy biến
riêng (branding "kensoft.cc"/"Alex Koj Modified" trong `VerInfo_Keys`).

## Cấu trúc thư mục

```
source/             Toàn bộ mã nguồn native (C++/Pascal) và project files (.cbproj)
  core/             Lõi không giao diện: SSH/SFTP/FTP/WebDAV/S3/SCP, Configuration,
                    SessionData, Terminal — biên dịch vào ScpCore.cbproj
  forms/            Các form/dialog VCL (.cpp/.h/.dfm): Login, CustomScpExplorer
                    (cửa sổ chính), Preferences, Editor, SiteAdvanced, Progress...
  windows/          Logic tầng ứng dụng: WinConfiguration, UserInterface (nơi set
                    theme lúc khởi động), VCLCommon (helper UI dùng chung, dark mode),
                    Tools.cpp (màu sắc trung tâm), TerminalManager, WinMain (entry point)
  components/       Component C++ tự viết: UnixDirView/UnixDriveView (danh sách file
                    remote), ThemePageControl (tab session — xem mục riêng bên dưới)
  packages/
    filemng/        CustomDirView.pas/DirViewInt.pas/DriveViewInt.pas — nền tảng
                    danh sách file local (base class cho DirView)
    my/             Component "Martin's" tự viết: NortonLikeListView (dark mode
                    native cho listview), HistoryComboBox, PasTools (Win32 dark
                    mode helpers, đọc registry AppsUseLightTheme)
    tbx/, tb2k/      Thư viện toolbar/menu bên thứ 3 (TBX) — có engine theme riêng
                    (TTBXOfficeXPTheme/TTBXDarkOfficeXPTheme, xem mục VCL Styles)
    png/            PngBitBtn/PngSpeedButton/PngCheckListBox — nút có icon PNG
    dragndrop/       Thư viện kéo-thả (namespace Dragdrop, có typedef IDataObject
                    riêng — coi chừng đụng độ với ::IDataObject COM khi include
                    mshtmhst.h/MSHTML.hpp, phải include các header COM đó TRƯỚC
                    khi WinPCH.h/FormsPCH.h kéo theo DragDrop.hpp)
  resource/         Icon .ico, resource string .rc
  windows/WinSCP.exe.manifest   Manifest app (bật comctl32 v6 + dark titlebar)
  WinSCP.groupproj  Định nghĩa thứ tự build tất cả project con
  WinSCP.cbproj     Project chính (WinSCP.exe)
deployment/         Script Inno Setup đóng gói installer (winscpsetup.iss) —
                    KHÔNG dùng khi chỉ build qua IDE, mong đợi file WinSCP.com
                    (build ra tên Console.com — cần đổi SanitizedProjectName của
                    Console.cbproj nếu muốn khớp tên, xem lịch sử trò chuyện)
build.bat           Script build dòng lệnh — KHÔNG dùng được vì lý do license
                    (xem mục Build bên dưới), chỉ còn giá trị tham khảo cấu hình
```

## Build — các điều bắt buộc phải biết

1. **Chỉ build được qua IDE RAD Studio**, không build dòng lệnh được: bản
   Community Edition **chặn `dcc32`/`bcc32`/`msbuild` chạy ngoài IDE** (báo lỗi
   "This version of the product does not support command line compiling").
   Trong IDE, dùng **Build All Projects** / **Rebuild All Projects** trên
   `WinSCP.groupproj`.
2. Cần set 2 biến môi trường IDE (Tools → Options → Environment Variables →
   User System Overrides), thiếu sẽ khiến output build lạc ra ngoài
   `F:\Win32\Release` (gốc ổ đĩa) thay vì `source\Win32\Release`, gây lỗi
   "Unable to find static library" khi link:
   - `INTERM_PATH` = `.`
   - `FINAL_PATH` = `.`
3. **`Manifest_File` trong `WinSCP.cbproj` hay bị IDE tự ghi đè về `(None)`**
   mỗi khi bạn lưu Project Options (kể cả sửa mục không liên quan như
   Appearance) — vì đây là dạng project cũ (ProjectVersion 19.5→20.4, IDE tự
   nâng cấp định dạng khi lưu). Thiếu manifest → app chạy theme Windows Classic
   xấu, và **nút X đóng tab session biến mất hoàn toàn** (xem mục
   ThemePageControl). Cách fix bền: set qua **Project Options → Application →
   Manifest file**, chọn `windows\WinSCP.exe.manifest`, Target =
   "All configurations - All platforms" — set qua UI thay vì sửa XML tay thì
   IDE mới nhớ được.
4. Mỗi project con trong `WinSCP.groupproj` có **platform đang chọn (active
   platform) riêng** — "Build All" build theo platform hiện tại của TỪNG
   project, không phải theo project chính. Muốn build Win64 phải chọn tất cả
   project (Ctrl+A trong Project Manager) rồi đổi Platform cùng lúc.
5. Build Win64 cần **MSVC v143 (VS2022) build tools** thật (không phải chỉ có
   compiler — cần đủ thư mục `MSBuild\Microsoft\VC\*\Platforms\Win32\
   PlatformToolsets\v143`). VS2026 Build Tools (bản mới) không có sẵn cái này,
   phải dùng VS2022 Build Tools chính thức.
6. Windows SDK hiện đại (RAD 13) đã fix xung đột `wininet.h`/`winhttp.h` bằng
   include-guard chung — nếu thấy workaround đổi tên
   `URL_COMPONENTS`/`INTERNET_SCHEME` kiểu cũ trong `Tools.cpp`, đó là code
   thừa/gây lỗi với SDK mới, nên bỏ (đã bỏ trong session này).

## Dark mode / VCL Styles — hiện trạng (đã làm trong session này)

WinSCP vốn có **hệ dark mode tự viết tay** (không dùng VCL Styles):
`WinConfiguration->DarkTheme` (Auto/On/Off) → `UseDarkTheme()` → 4 hàm màu
trung tâm trong `windows/Tools.cpp` (`GetWindowColor`, `GetBtnFaceColor`,
`GetWindowTextColor`, `GetLinkColor`) + theme riêng cho TBX
(`TTBXOfficeXPTheme`/`TTBXDarkOfficeXPTheme` trong `packages/tbx/
TBXOfficeXPTheme.pas`) + Win32 dark titlebar/scrollbar API thủ công
(`ApplyColorMode`/`UseDarkMode`/`ApplyDarkModeOnControl` trong
`windows/VCLCommon.cpp`).

**Đã chuyển sang VCL Styles** (chọn style **"Onyx Blue"** cho dark mode, giữ
style "Windows" mặc định cho light mode để tối thiểu rủi ro):

- Style nhúng qua Project Options → Application → Appearance (KHÔNG sửa XML
  tay được, IDE tự quản lý `Custom_Styles` property).
- `windows/UserInterface.cpp` — `ConfigureInterface()`: kích hoạt
  `TStyleManager::TrySetStyle()` **chỉ 1 lần lúc khởi động**. **Đã thử bỏ
  guard này để đổi style live khi toggle Dark/Light → layout loạn và app sập,
  đã revert** — TBX toolbar/menu + docking layout không sống sót qua cascade
  `CM_STYLECHANGED` của VCL Styles. Đừng bỏ guard lần nữa nếu chưa xử lý được
  phía TBX. Hệ quả chấp nhận được: đổi Dark↔Light thì TBX theme và màu
  `Tools.cpp` đổi ngay, riêng "skin" VCL Style phải khởi động lại mới khớp
  (Dark→Light nền vẫn tối cho tới lần chạy sau).
  **Thứ tự quan trọng**: phải set VCL Style TRƯỚC khi gọi `TBXSetTheme()`,
  vì TBX tính màu (`SetupColorCache`) dựa vào `TStyleManager.ActiveStyle`
  đang có tại thời điểm đó.
- `windows/Tools.cpp` — 4 hàm màu trung tâm giờ ưu tiên lấy màu qua
  `Vcl::Themes::StyleServices()->GetSystemColor(...)` khi có VCL Style
  non-default đang chạy, fallback về logic cũ nếu không.
- `packages/tbx/TBXOfficeXPTheme.pas` — thêm hàm `ActiveVclStyleColor()` để
  `MenubarColor`/`ToolbarColor`/`PopupColor`/`GetStandardColor()` (dark mode)
  lấy màu theo VCL Style thật thay vì hardcode xám/đen.
- **28 form/dialog** trước đó thiếu `ApplyColorMode(this)` (bị bỏ sót từ khi
  viết dark mode ban đầu, không liên quan VCL Styles) đã được bổ sung: About,
  Preferences, Cleanup, CopyLocal, CopyParamCustom, CopyParamPreset,
  CreateDirectory, Custom, CustomCommand, EditMask, Editor,
  EditorPreferences, FileFind, FileSystemInfo, FullSynchronize, GenerateUrl,
  ImportSessions, License, LocationProfiles, OpenDirectory, Properties,
  RemoteTransfer, SelectMask, SiteAdvanced, Symlink, Synchronize,
  SynchronizeChecklist, SynchronizeProgress. **Cố tình không đụng**
  `CustomScpExplorer.cpp` (đã có cơ chế dark mode riêng phức tạp hơn) và
  `Console.cpp` (màu terminal do user tự cấu hình).
- `packages/filemng/CustomDirView.pas` — set `StyleElements := [seFont];`
  trong constructor `TCustomDirView`, để VCL Styles không "style-hook" đè lên
  phần nền/viền (control này tự quản lý màu native rồi) — sửa lỗi **nháy màn
  hình khi rê chuột qua file list**.

### `ThemePageControl.cpp` (tab session) — bài học quan trọng

Class `TThemePageControl` (dùng cho `SessionsPageControl`) có NHIỀU chỗ kiểm
tra `UseThemes()` (theme Windows **cổ điển**, comctl32 v6 qua manifest — khác
hẳn VCL Styles) để quyết định có chạy code vẽ tab tùy chỉnh hay không. Nếu
`UseThemes()` = false (dù VCL Style vẫn đang chạy tốt), **toàn bộ code vẽ tùy
chỉnh của class này bị bỏ qua hoàn toàn**, rơi về `TPageControl::PaintWindow`
gốc của VCL — và VCL Styles vẫn tự tô màu đẹp lên control gốc đó một cách độc
lập, khiến tab **trông vẫn đúng theme** dù không hề chạy qua code của class
này — đây là bẫy rất dễ gây hiểu lầm khi debug (tab vẫn đẹp, nhưng nút X đóng
tab biến mất hoàn toàn, sửa code vẽ nút X không có tác dụng gì vì code đó
không được gọi).

**Đã sửa**: thêm hàm dùng chung `IsPageControlThemed()` (đầu file
`ThemePageControl.cpp`) = `UseThemes() || (có VCL Style non-default đang
chạy)`, thay `UseThemes()` bằng hàm này ở MỌI chỗ liên quan đến vẽ/không gian
dành cho nút: `PaintWindow` (chỗ quan trọng nhất — gate chính), `GetTabButton`,
`UpdateCaption`, `Change`. Cũng đã đổi cách vẽ dấu X từ vẽ đường thẳng GDI thủ
công (`MoveToEx`/`LineTo`) sang vẽ ký tự `"×"` qua `DrawText` (đáng tin cậy
hơn, tái dùng đúng cơ chế vẽ chữ tab đã chứng minh hoạt động).

**Nhưng đó CHƯA phải nguyên nhân gốc** (nút X vẫn không hiện sau fix trên):
`Vcl.ComCtrls` đăng ký sẵn **`TTabControlStyleHook` cho `TCustomTabControl`**.
Khi có VCL Style non-default, hook này bật `OverridePaint` và **tự vẽ toàn bộ
control ngay trong `WM_PAINT`** → `TThemePageControl::PaintWindow` **không hề
được gọi**, bất kể `IsPageControlThemed()` trả về gì. Tab vẫn trông đẹp (hook
vẽ), click vẫn đóng tab (`WM_LBUTTONDOWN` đi qua `Dispatch`, hook không đụng
tới), chỉ có nút X là không bao giờ được vẽ.

**Đã sửa** (`ThemePageControl.cpp`) — cách dứt điểm là **không phụ thuộc vào
việc ai đang chiếm `WM_PAINT`**:
- `DrawTabButtons()` + override `WndProc`: sau khi gọi
  `TPageControl::WndProc()` (để PaintWindow *hoặc* style hook vẽ xong tab),
  lấy `GetDC(Handle)` và vẽ nút X **đè lên trên**. Chạy đúng trong cả 3 trường
  hợp (PaintWindow của class này / TPageControl gốc / style hook). Phần vẽ nút
  đã tách khỏi `DrawTabItem` (chỉ chạy khi PaintWindow chạy) sang
  `DrawTabButton()`.
- **Đã thử và ĐÃ GỠ** các cách opt-out khỏi style hook: đăng ký `TStyleHook`
  gốc cho `TThemePageControl` qua `TCustomStyleEngine::RegisterStyleHook`,
  `ControlStyle << csOverrideStylePaint`, bỏ `seClient`/`seBorder` khỏi
  `StyleElements`. Không cách nào làm nút X hiện ra, nên đã gỡ hết thay vì để
  lại rủi ro chết (chúng can thiệp sâu vào cách VCL Styles đối xử với control).
- Vẽ nút X bằng **GDI lines** (`MoveToEx`/`LineTo`), không dùng glyph font —
  lớp vẽ đè chạy sau khi người khác đã vẽ nên không được phụ thuộc font đang
  select trong DC. Màu suy ra từ **màu nền thật trên màn hình** (`GetPixel`):
  nền tối → glyph sáng, nền sáng → glyph tối.
- **TUYỆT ĐỐI không deref `TabTheme`/`ActiveTabTheme` trong lớp vẽ đè**: đây là
  con trỏ cache, còn lớp vẽ đè chạy ở *mọi* `WM_PAINT` — kể cả những paint rơi
  đúng khoảng giữa lúc `TBXSetTheme()` hủy theme cũ và `UpdateControls()` gán
  theme mới. Deref con trỏ treo ở đó làm **app sập mỗi lần đổi Dark/Light**
  (và vì sập nên layout không được lưu sạch → lần chạy sau layout loạn, dễ bị
  hiểu nhầm là lỗi layout). Chỉ dùng biến global `CurrentTheme` của TBX, có
  kiểm tra NULL.
- **Chỉ được vẽ nút ở MỘT nơi** (`DrawTabButtons`), không vẽ thêm trong
  `DrawTabItem`: lớp vẽ đè lấy màu nền bằng `GetPixel`, nếu lấy ở tâm nút thì
  nó đọc trúng nét X của lần vẽ trước → `ContrastingColor` lật màu → X thành
  đúng màu nền. Vì vậy điểm lấy mẫu đặt ở **bên trái glyph** (`Left + Inset/2`),
  vùng mà nét X không bao giờ chạm tới.
- **Hai cái bẫy của lớp vẽ đè** (đều chỉ lộ ở dark mode): (1) phải dùng
  `GetDCEx(Handle, NULL, DCX_CACHE)` chứ không `GetDC()` — `GetDC` =
  `DCX_USESTYLE` mà TWinControl tạo cửa sổ với `WS_CLIPCHILDREN`, nên DC bị
  clip mất vùng child; (2) `GetPixel` trả `CLR_INVALID` (0xFFFFFFFF) khi điểm
  nằm ngoài clip region — nếu coi đó là màu thì ra "nền trắng" và
  `ContrastingColor` chọn glyph **đen trên nền tối** = vô hình.
- Chuyển phần vẽ nút ra **ngoài** nhánh `if (!Text.IsEmpty())`: trước đây mở
  nhiều tab đến mức caption bị cắt sạch (`tttNoText`) thì nút X cũng mất theo.

**Nếu sau này gặp UI nào "vẽ tùy chỉnh không xuất hiện dù code đúng, nhưng bề
ngoài vẫn ổn"**: nghi ngờ theo thứ tự (1) **VCL Style hook đang chiếm
`WM_PAINT`** của control đó (`Vcl.ComCtrls`/`Vcl.StdCtrls` đăng ký hook cho
hầu hết control chuẩn), (2) một điều kiện `UseThemes()`/theme cổ điển nào đó
đang gate nhầm — cả hai đều bị VCL Styles "che" mất triệu chứng thật.

## Thông báo khởi động lại khi đổi color mode

Vì VCL Style chỉ nạp lúc khởi động, khi user đổi Dark/Light trong Preferences mà
style hiện tại không khớp mode mới, app hỏi 3 lựa chọn (`ConfirmColorModeRestart()`
trong `windows/UserInterface.cpp`): **Restart now** / **Restart later** / **Cancel**
(Cancel = trả lại thiết lập cũ, không lưu).

- Chuỗi: `COLOR_MODE_RESTART`, `COLOR_MODE_RESTART_NOW`, `COLOR_MODE_RESTART_LATER`
  (ID 1377–1379) trong `resource/TextsWin.h` + `resource/TextsWin1.rc`.
- "Restart now" chỉ **PostMessage(WM_CLOSE)** cho main form (dialog Preferences
  vẫn đang modal, không được đóng main form ngay dưới chân nó) và ghi lại đường
  dẫn exe; việc chạy lại thật sự do `RestartApplicationIfRequested()` làm ở
  **cuối `wWinMain`** (`WinSCP.cpp`), sau khi config đã được ghi — nếu chạy sớm
  hơn thì instance mới đọc phải config cũ.
- Gọi từ `forms/Preferences.cpp` ngay sau khi gán `WinConfiguration->DarkTheme`.

## Các tính năng đã thêm/sửa khác trong session này

- **Notes trong Login form**: gõ trực tiếp được (không cần vào Advanced),
  nhưng **chỉ khi đang bấm Edit** (giống Host/User/Password), tự khoá lại
  read-only sau khi Save. Sửa ở `forms/Login.cpp`
  (`LoadSession`/`SaveSession`/`UpdateControls`) và `windows/VCLCommon.cpp`
  (`DoReadOnlyControl` — bug cũ: bật readonly=false trên TMemo không khôi
  phục lại `WantReturns`, khiến Enter/gõ chữ không hoạt động).
- **Dialog "Advanced" (SiteAdvanced) mở chậm**: đã cache 1 instance dùng lại
  xuyên suốt vòng đời app thay vì tạo/hủy mỗi lần mở (`forms/SiteAdvanced.cpp`,
  `DoSiteAdvancedDialog`) — nhanh hẳn từ lần mở thứ 2.
- **Load thư mục nhiều file bị lag**: `packages/filemng/DirViewInt.pas` quét
  thư mục **2 lần riêng biệt** (1 lần file, 1 lần thư mục con) trong cả
  `LoadFiles` và `Reload2` (dùng khi >100 item) — đã gộp thành 1 lần quét duy
  nhất (mask `FileAttr` vốn đã bao trùm cả thư mục/ẩn/hệ thống).
- **Retry đăng nhập khi sai password**: `windows/TerminalManager.cpp`,
  `TTerminalManager::NewSession` — bỏ giới hạn "chỉ retry cho site chưa lưu",
  giờ site đã lưu cũng được tự mở lại Login dialog khi kết nối thất bại (dù
  cơ chế "Site &Manager..." action có sẵn trên menu Files vẫn luôn dùng được
  để mở lại Login thủ công).

## Mẹo khi làm việc tiếp

- Đọc file XML `.cbproj` để kiểm tra **hiện trạng thật** trước khi sửa —
  chúng hay bị IDE resave/upgrade format (`ProjectVersion` 19.5 → 20.4) và
  một số property (đặc biệt `Manifest_File`) bị reset về giá trị mặc định.
- Trước khi kết luận 1 fix "không có tác dụng", cân nhắc khả năng code path
  đó **không hề được gọi** (xem bài học `ThemePageControl` ở trên) thay vì cứ
  giả định logic bên trong sai.
- Ưu tiên sửa tận gốc ở các hàm/helper dùng chung (`Tools.cpp`,
  `VCLCommon.cpp`) hơn là sửa lặp lại ở từng form, vì phần lớn code đã đi qua
  các điểm trung tâm này.
