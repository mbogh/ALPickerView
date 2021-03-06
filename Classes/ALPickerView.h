//
//  ALPickerView.h
//
//  Created by Alex Leutgöb on 16.01.11.
//  Copyright 2011 alexleutgoeb.com. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#import <Foundation/Foundation.h>

@protocol ALPickerViewDelegate;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


@interface ALPickerView : UIView <UIPickerViewDelegate, UIPickerViewDataSource> {
@private
	UIPickerView *internalPickerView;
	id<ALPickerViewDelegate> delegate;
	BOOL allOption;
	NSString *allOptionTitle;
}

// Set a delegate conforming to ALPickerViewDelegate protocol
@property (nonatomic, assign) id<ALPickerViewDelegate> delegate;
// Set wether an all option should be displayed or not
@property (nonatomic, assign) BOOL allOption;
// Set the all option title to display in first row, default is 'All'
@property (nonatomic, retain) NSString *allOptionTitle;

@end


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


@protocol ALPickerViewDelegate <NSObject>

// Return the number of elements of your pickerview
- (NSInteger)numberOfRowsForPickerView:(ALPickerView *)pickerView;
// Return a plain UIString to display on the given row
- (NSString *)pickerView:(ALPickerView *)pickerView textForRow:(NSInteger)row;
// Return a boolean selection state on the given row
- (BOOL)pickerView:(ALPickerView *)pickerView selectionStateForRow:(NSInteger)row;

@optional

// Inform the delegate that a row got selected, if row = -1 all rows are selected
- (void)pickerView:(ALPickerView *)pickerView didCheckRow:(NSInteger)row;
// Inform the delegate that a row got deselected, if row = -1 all rows are deselected
- (void)pickerView:(ALPickerView *)pickerView didUncheckRow:(NSInteger)row;

@end
