/*
 *
 *    Copyright (c) 2024 Project CHIP Authors
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */
#include <pw_unit_test/framework.h>

#include <SilabsTestEventTriggerDelegate.h>
#include <lib/support/Span.h>

using namespace chip;

namespace {
const uint8_t kTestEnableKey[TestEventTriggerDelegate::kEnableKeyLength]    = { /* some test key data */ };
const uint8_t kInvalidEnableKey[TestEventTriggerDelegate::kEnableKeyLength] = { 0 };
} // namespace

TEST(TestSilabsTestEventTriggerDelegate, TestDoesEnableKeyMatch_ValidKey)
{
    SilabsTestEventTriggerDelegate delegate;
    ByteSpan validKeySpan(kTestEnableKey);
    EXPECT_TRUE(delegate.DoesEnableKeyMatch(validKeySpan));
}

TEST(TestSilabsTestEventTriggerDelegate, TestDoesEnableKeyMatch_InvalidKey)
{
    SilabsTestEventTriggerDelegate delegate;
    ByteSpan invalidKeySpan(kInvalidEnableKey);
    EXPECT_FALSE(delegate.DoesEnableKeyMatch(invalidKeySpan));
}

TEST(TestSilabsTestEventTriggerDelegate, TestDoesEnableKeyMatch_EmptyKey)
{
    SilabsTestEventTriggerDelegate delegate;
    ByteSpan emptyKeySpan;
    EXPECT_FALSE(delegate.DoesEnableKeyMatch(emptyKeySpan));
}
