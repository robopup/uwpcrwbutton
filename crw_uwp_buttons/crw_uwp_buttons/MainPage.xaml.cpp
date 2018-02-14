//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include <fstream>

using namespace crw_uwp_buttons;
using namespace std;
using namespace concurrency;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

using namespace Windows::Storage;
using namespace Windows::Storage::Pickers;
using namespace Windows::Storage::Streams;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
}


void crw_uwp_buttons::MainPage::writeFile_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	ButtonOutput->Text = "You pushed the button!";

	FolderPicker^ openStoragePicker = ref new FolderPicker();
	openStoragePicker->ViewMode = PickerViewMode::Thumbnail;
	openStoragePicker->SuggestedStartLocation = PickerLocationId::ComputerFolder;
	openStoragePicker->FileTypeFilter->Append("*");

	// Create File in selected folder using FolderPicker
	create_task(openStoragePicker->PickSingleFolderAsync()).then([this](StorageFolder^ storageFolder)
	{
		create_task(storageFolder->CreateFileAsync("sampleFile.txt", CreationCollisionOption::ReplaceExisting));
	});

	// Pick and open the file
	auto mru = Windows::Storage::AccessCache::StorageApplicationPermissions::MostRecentlyUsedList;
	string mruToken = mru->Add()
	
}
