# Build Log – Repository Setup & Initial Push

**Date:** 30 June 2026
**Time:** 10:00  - 12:00

## Overview

Set up the local DSA Library project as a Git repository and connected it to the GitHub organization repository.

## Steps Performed

### 1. Created GitHub Repository

* Created the repository `ds_library-nikita` under the organization.

### 2. Initialized Local Repository

```bash
git init
```

### 3. Added Project Files

```bash
git add .
```

**Note:** Received a line-ending warning (`LF` to `CRLF`), which was informational and did not affect the workflow.

### 4. Created Initial Commit

```bash
git commit -m "initial commit(Project folder structure and initial proposal)"
```

### 5. Connected Local Repository to GitHub

```bash
git remote add origin https://github.com/SuperCodersOrg/ds_library-nikita.git
```

### 6. Renamed Branch to Main

```bash
git branch -M main
```

### 7. Attempted First Push

```bash
git push -u origin main
```

## Issue Encountered

### Push Rejected

**Error:**

```text
! [rejected] main -> main (fetch first)
```

**Reason:**
The remote repository already contained commits, causing the local and remote histories to differ.

## Resolution

Pulled the remote changes and merged the histories:

```bash
git pull origin main --allow-unrelated-histories
```

During the merge process:

* A merge commit message editor opened.
* Saved the generated merge message.
* Completed the merge commit.

Verified repository status:

```bash
git status
```

Output:

```text
On branch main
nothing to commit, working tree clean
```

## Final Push

```bash
git push -u origin main
```

## Result

* Repository successfully connected to GitHub.
* Initial project structure uploaded.
* Local `main` branch linked to `origin/main`.
* Repository ready for further development.

## Future Workflow

```bash
git add .
git commit -m "Describe changes"
git push
```
